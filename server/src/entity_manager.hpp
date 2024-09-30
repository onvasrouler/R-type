/*
** EPITECH PROJECT, 2024
** R-Type
** File description:
** Entity Manager
*/

#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <vector>
#include <cstddef>
#include "registry.hpp"

class EntityManager {
public:
    using entity_t = Registry::entity_t;

    EntityManager(Registry& registry) : _registry(registry) {}

    entity_t spawn_entity();
    entity_t entity_from_index(std::size_t idx);
    void kill_entity(entity_t& e);

    template <typename Component>
    typename sparse_array<Component>::reference_type add_component(entity_t const& to, Component&& c);

    template <typename Component, typename... Params>
    typename sparse_array<Component>::reference_type emplace_component(entity_t const& to, Params&&... p);

    template <typename Component>
    void remove_component(entity_t const& from);

private:
    Registry& _registry;
};

template <typename Component>
typename sparse_array<Component>::reference_type EntityManager::add_component(entity_t const& to, Component&& c) {
    return _registry.add_component(to, std::forward<Component>(c));
}

template <typename Component, typename... Params>
typename sparse_array<Component>::reference_type EntityManager::emplace_component(entity_t const& to, Params&&... p) {
    auto& array = _registry.get_component_array<Component>();
    return array.emplace_at(to, std::forward<Params>(p)...);
}

template <typename Component>
void EntityManager::remove_component(entity_t const& from) {
    _registry.remove_component<Component>(from);
}

#endif /* !ENTITY_MANAGER_HPP_ */
