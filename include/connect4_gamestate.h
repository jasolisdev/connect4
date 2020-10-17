#ifndef CONNECT4_GAMESTATE_H
#define CONNECT4_GAMESTATE_H 

#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class tiny_state
{
public:
	EntityManager manager;
	virtual void Initialize(sf::RenderWindow* Window)
	{
	}
	virtual void Update(sf::RenderWindow* Window)
	{
	}
	virtual void Render(sf::RenderWindow* Window)
	{
	}
	virtual void Destroy(sf::RenderWindow* Window)
	{
	}
private:
};

class connect4_gamestate
{
public:
	connect4_gamestate(sf::RenderWindow* Window)
	{
		this->Window = Window;
	}

	void SetState(tiny_state* nextState)
	{
		if (this->state != NULL)
		{
			 /* this->state->Destroy(this->Window); */
		}
		this->state = nextState;
		if (this->state != NULL)
		{
			this->state->Initialize(this->Window);
		}
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->Window);
			this->state->Render(this->Window);
		}
	}

	~connect4_gamestate()
	{
		if (this->state != NULL)
		{
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
