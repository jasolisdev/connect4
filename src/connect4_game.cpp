#include <stdio.h>
#include <string>

#include "../include/connect4_game.h"
#include "../include/connect4_chip.h" 
#include <iostream>

int redCount = 21;
int blackCount = 21;

bool redTurn = true;
bool blackTurn = false;
bool isRed = false;

void connect4_game::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("assets/Ubuntu.ttf");

    this->redChipsText = new sf::Text("Red Chips: 21", *font, 32U);
    this->redChipsText->setFillColor(sf::Color::Red);
	this->redChipsText->setPosition(sf::Vector2f(20, 10));
	
    this->blackChipsText = new sf::Text("Black Chips: 21", *font, 32U);
    this->blackChipsText->setFillColor(sf::Color::Black);
	this->blackChipsText->setPosition(sf::Vector2f(750 - this->blackChipsText->getGlobalBounds().width, 10));
}

void connect4_game::ProcessInput(sf::Event event)
{
    int X = event.mouseButton.x;
    int Y = event.mouseButton.y;

    if (sf::Event::MouseButtonPressed && 
            event.mouseButton.button == sf::Mouse::Left && redTurn == true) 
    {
        isRed = true;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        this->manager.AddEntity("Red Chip", new Chip(X, Y, isRed));

        redTurn = false;
        blackTurn = true;
    }
    if (sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Right && blackTurn == true) 
    {
        isRed = false;

        std::cout << "X: " << X << " Y: " << Y << std::endl;
        this->manager.AddEntity("Black Chip", new Chip(X, Y, isRed));

        blackTurn = false;
        redTurn = true;
    }

    this->manager.ProcessInput();
}

void connect4_game::Update(sf::RenderWindow* window)
{
    if (redCount == 0 && blackCount == 0)
    {
        this->redChipsText->setString("Red Chips: 0");
        this->blackChipsText->setString("Black Chips: 0");
    }else
    {
        this->redChipsText->setString("Red Chips: " + std::to_string(redCount));
        this->blackChipsText->setString("Black Chips: " + std::to_string(blackCount));
    }

	this->manager.Update();
}

void connect4_game::Render(sf::RenderWindow* window)
{
	this->manager.Render(window);
	window->draw(*this->redChipsText);
	window->draw(*this->blackChipsText);
}

void connect4_game::Destroy(sf::RenderWindow* window)
{
}
