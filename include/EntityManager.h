#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Entity.h"

class EntityManager {
 public:
  EntityManager() {}

  void AddEntity(std::string name, Entity *entity) {
    std::map<std::string, Entity *>::iterator found = this->entities.find(name);
    while (found != this->entities.end()) {
      name += "0";
      found = this->entities.find(name);
    }
    this->entities.insert(std::make_pair(name, entity));
  }

  void ProcessInput() {}

  void Update() {
    for (auto &iterator : this->entities) {
      if (iterator.second->Active()) {
        iterator.second->Update();
      }
    }
  }

  void Reset() {
    this->entities.clear();
    this->toRemove.clear();
  }

  void Render(sf::RenderWindow *window) {
    for (auto &iterator : this->entities) {
      iterator.second->Render(window);
    }
  }

  ~EntityManager() {}

 private:
  std::map<std::string, Entity *> entities;
  std::vector<std::string> toRemove;
};

#endif /* ifndef ENTITYMANAGER_H */
