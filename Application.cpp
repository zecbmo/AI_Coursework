#include "Application.h"

Application::~Application()
{
	
}

void Application::Init(sf::RenderWindow * Window, int ScreenWidth, int ScreenHeight)
{
	//Set window pointers and define the screen res
	m_Window = Window;
	m_ScreenWidth = ScreenWidth;
	m_ScreenHeight = ScreenHeight;

	//Load up the debug system
	DebugSystem::Init("Assets/Font/font.ttf", SCREEN_MESSAGE_X_OFFSET, ScreenHeight - (SCREEN_MESSAGE_Y_OFFSET * FONT_SCALE));

	DebugSystem::Log("Initialising Applciation and Debug System");

	Temp.Init("Assets/Textures/RedPlayer.png", sf::Vector2f(400, 300));

}

void Application::Update(float dt)
{
	//Call debug Update at the end of the update function
	DebugSystem::Update();
}

void Application::Render()
{

	Temp.Render(m_Window);

	//Call debug Render at the end of the Render function
	DebugSystem::Render(m_Window);
}
