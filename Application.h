#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "DebugSystem.h"
#include <list>
#include "GameObject.h"
#define SCREEN_MESSAGE_Y_OFFSET 40
#define SCREEN_MESSAGE_X_OFFSET 10

class Application
{
public:
	Application() {};
	~Application();

	/**
	*	The Intialiser function
	*	Will initialse all variables and set up the player/server/client
	*
	*	@param RenderWindow pointer to the created SFML window
	*	@param ScreenWidth the set screen width
	*	@param ScreenHeight the set screen height
	*
	*/
	void Init(sf::RenderWindow* Window, int ScreenWidth, int ScreenHeight);

	/**
	*	Update the main game loop
	*
	*	@param delta time
	*/
	void Update(float dt);

	/**
	*	Render all objects to the SFML window
	*
	*/
	void Render();


private:
	sf::RenderWindow* m_Window;
	int m_ScreenWidth;
	int m_ScreenHeight;

	GameObject Temp;
	
	
};