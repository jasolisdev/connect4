#ifndef CONNECT4_GAMESTATE_H
#define CONNECT4_GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "EntityManager.h"

class tiny_state {
 public:
  EntityManager manager;
  virtual void Initialize(sf::RenderWindow* Window) {}
  virtual void ProcessInput(sf::RenderWindow* Window, sf::Event event) {}
  virtual void Update(sf::RenderWindow* Window) {}
  virtual void Render(sf::RenderWindow* Window) {}
  virtual void Destroy(sf::RenderWindow* Window) {}
};

class connect4_gamestate {
 public:
  connect4_gamestate(sf::RenderWindow* Window) { this->Window = Window; }

  void SetState(tiny_state* nextState) {
    if (this->state != NULL) {
      // this->state->Destroy(this->Window);
    }
    this->state = nextState;
    if (this->state != NULL) {
      this->state->Initialize(this->Window);
    }
  }

  void ProcessInput(sf::RenderWindow* window, sf::Event event) {
    if (this->state != NULL) {
      this->state->ProcessInput(window, event);
    }
  }

  void Update() {
    if (this->state != NULL) {
      this->state->Update(this->Window);
    }
  }

  void Render() {
    if (this->state != NULL) {
      this->state->Render(this->Window);
    }
  }

  ~connect4_gamestate() {
    if (this->state != NULL) {
      this->state->Destroy(this->Window);
    }
  }
  tiny_state* state;

 private:
  sf::RenderWindow* Window;
};

extern connect4_gamestate* coreState;
extern bool exitGame;

#endif /* ifndef CONNECT4_GAMESTATE_H */
