#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite {
 public:
  Entity() {
    this->active = 1;
    this->texture = new sf::Texture();
  }
  Entity(std::string filename) {
    this->active = 1;
    this->texture = new sf::Texture();
    this->Load(filename, sf::IntRect());
  }
  Entity(std::string filename, sf::IntRect size) {
    this->active = 1;
    this->texture = new sf::Texture();
    this->Load(filename, size);
  }

  void Load(std::string filename, sf::IntRect size) {
    this->texture->loadFromFile(filename, size);
    this->setTexture(*this->texture);
  }

  void createBox(sf::RectangleShape box) {
    this->box.setSize(sf::Vector2f(100, 50));
    this->box.setOutlineColor(sf::Color::Red);
    this->box.setFillColor(sf::Color::Transparent);
    this->box.setOutlineThickness(5);
    /* this->texture->loadFromFile(filename, size); */
    /* this->setTexture(*this->texture); */
  }

  bool collision(Entity* entity) {
    return (this->getGlobalBounds().intersects(entity->getGlobalBounds()));
  }

  int Active() { return this->active; }

  int Group() { return this->group_id; }

  virtual void Update() {}

  virtual void Render(sf::RenderWindow* window) { window->draw(*this); }

  ~Entity() {}

 protected:
  int active;
  int group_id;

 private:
  sf::Texture* texture;
  sf::RectangleShape box;
};

#endif /* ifndef ENTITY_H */
