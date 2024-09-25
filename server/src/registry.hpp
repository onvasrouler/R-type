/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Bs
*/

#ifndef REGISTRY_HPP_
#define REGISTRY_HPP_

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <any>
#include <stdexcept>
#include <functional>
#include <vector>
#include <tuple>
#include "sparse_array.hpp"

class EntityManager;

class Registry {
public:
    using entity_t = size_t;

    template <typename Component>
    sparse_array<Component>& register_component();

    template <typename Component>
    sparse_array<Component>& get_component_array();

    template <typename Component>
    sparse_array<Component> const& get_component_array() const;

    template <typename Component>
    void add_component(entity_t entity, Component&& component);

    template <typename Component>
    void remove_component(entity_t entity);

    entity_t create_entity();
    void destroy_entity(entity_t entity);

    template <class... Components, typename Function>
    void add_system(Function&& f);

    void run_systems();

    friend class EntityManager;

private:
    std::unordered_map<std::type_index, std::any> _component_arrays;
    std::unordered_map<std::type_index, std::function<void(Registry&, entity_t const&)>> _erase_functions;
    std::vector<entity_t> _entities;
    std::vector<entity_t> _free_entities;
    std::vector<std::function<void(Registry&)>> _systems;
};

template <typename Component>
sparse_array<Component>& Registry::register_component() {
    auto type_index = std::type_index(typeid(Component));
    auto it = _component_arrays.find(type_index);
    if (it == _component_arrays.end()) {
        _component_arrays[type_index] = std::make_shared<sparse_array<Component>>();
        _erase_functions[type_index] = [this](Registry& registry, entity_t const& entity) {
            registry.remove_component<Component>(entity);
        };
    }
    return *std::any_cast<std::shared_ptr<sparse_array<Component>>>(_component_arrays[type_index]);
}

template <typename Component>
sparse_array<Component>& Registry::get_component_array() {
    auto type_index = std::type_index(typeid(Component));
    auto it = _component_arrays.find(type_index);
    if (it == _component_arrays.end()) {
        throw std::runtime_error("Component type not registered");
    }
    return *std::any_cast<std::shared_ptr<sparse_array<Component>>>(it->second);
}

template <typename Component>
sparse_array<Component> const& Registry::get_component_array() const {
    auto type_index = std::type_index(typeid(Component));
    auto it = _component_arrays.find(type_index);
    if (it == _component_arrays.end()) {
        throw std::runtime_error("Component type not registered");
    }
    return *std::any_cast<std::shared_ptr<sparse_array<Component>>>(it->second);
}

template <typename Component>
void Registry::add_component(entity_t entity, Component&& component) {
    auto& array = get_component_array<Component>();
    array.insert_at(entity, std::forward<Component>(component));
}

template <typename Component>
void Registry::remove_component(entity_t entity) {
    auto& array = get_component_array<Component>();
    array.erase(entity);
}

template <class... Components, typename Function>
void Registry::add_system(Function&& f) {
    _systems.emplace_back([this, f = std::forward<Function>(f)](Registry& r) {
        f(r, get_component_array<Components>()...);
    });
}

#endif /* !REGISTRY_HPP_ */
