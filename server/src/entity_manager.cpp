#include "entity_manager.hpp"

EntityManager::entity_t EntityManager::spawn_entity() {
    return _registry.create_entity();
}

EntityManager::entity_t EntityManager::entity_from_index(std::size_t idx) {
    if (idx < _registry._entities.size()) {
        return _registry._entities[idx];
    }
    throw std::out_of_range("Entity index out of range");
}

void EntityManager::kill_entity(entity_t const& e) {
    _registry.destroy_entity(e);
}
