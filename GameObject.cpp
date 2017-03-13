#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Init(std::string Filename, sf::Vector2f StartingPos)
{

	//Load the texture and apply it to the player Sprite		
	if (!m_Texture.loadFromFile(Filename))
	{
		DebugSystem::ErrorMessageWithID(Filename, "Unable to load image in player character");
	}

	m_Sprite.setTexture(m_Texture);

	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);

	m_Sprite.setPosition(StartingPos);


	DebugSystem::Log(("New Game Object Created: " + Filename));
}

void GameObject::Update(float dt)
{
}

void GameObject::Render(sf::RenderWindow * Window)
{
	Window->draw(m_Sprite);
}
