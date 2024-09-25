#include "registry.hpp"

Registry::entity_t Registry::create_entity() {
    entity_t new_entity;
    if (!_free_entities.empty()) {
        new_entity = _free_entities.back();
        _free_entities.pop_back();
    } else {
        new_entity = _entities.size();
        _entities.push_back(new_entity);
    }
    return new_entity;
}

void Registry::destroy_entity(entity_t entity) {
    for (auto& erase_func : _erase_functions) {
        erase_func.second(*this, entity);
    }
    _free_entities.push_back(entity);
}

void Registry::run_systems() {
    for (auto& system : _systems) {
        system(*this);
    }
}