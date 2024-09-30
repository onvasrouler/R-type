#include "registry.hpp"

Registry::entity_t Registry::create_entity() {
    size_t id;
    if (!_free_entities.empty()) {
        id = _free_entities.back()->get_id();
        _free_entities.pop_back();
    } else {
        id = _entities.size();
        _entities.emplace_back(std::make_shared<Player>(0, 0, 0, 0));
    }
    return _entities.back();
}

void Registry::destroy_entity(entity_t& entity) {
    size_t id = entity->get_id();
    if (id < _entities.size()) {
        _free_entities.emplace_back(entity);
        for (auto& [type, erase_func] : _erase_functions) {
            erase_func(*this, entity);
        }
    }
}

void Registry::run_systems() {
    for (auto& system : _systems) {
        system(*this);
    }
}
