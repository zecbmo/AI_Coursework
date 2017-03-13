#pragma once

#include<SFML\Graphics.hpp>
#include "DebugSystem.h"
#include "Vector2.h"
/**
*	The GameObject Class
*
*	The base gamobject will represent objects that will be visible on screen
*	They include Sprites a transform
*
*	ID's will be given to each game object
*
*/

class GameObject
{
public:
	GameObject();
	~GameObject();

	/**
	*	The Initialiser for the GameObject
	*
	*	@param The starting position
	*	@param the Filename location the textures for the GameObject
	*/
	void Init(std::string Filename, sf::Vector2f StartingPos = sf::Vector2f(0, 0));

	/**
	*	Update Function
	*
	*	all chlid members must have an update funciton 
	*	@param Delta Time 
	*/
	virtual void Update(float dt);


	/**
	*	The Render Function
	*
	*	@param Pointer to the SFML window
	*/
	void Render(sf::RenderWindow* Window);


protected:
	
	/**
	*	Members controlling sprite
	*/
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

	Vector2 m_Position;
};

