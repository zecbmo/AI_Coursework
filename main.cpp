#include <SFML/Graphics.hpp>
#include "DebugSystem.h"
#include "Application.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

int main()
{
	//Register a new window
	sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "AI Coursework");

	//Declare the clear colour
	sf::Color ClearColour(50, 50, 50, 255);

	//Declare the clock to manage delta time
	sf::Clock DeltaClock;

	//Int the Application
	Application Game;
	Game.Init(&Window, SCREEN_WIDTH, SCREEN_HEIGHT);

	while (Window.isOpen())
	{
		//Set up the clock and delta time 
		sf::Time FrameTime = DeltaClock.restart();
		float DeltaTime = FrameTime.asSeconds();

		//Poll for closing the window
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}

		//Clear window
		Window.clear(ClearColour);
		
		//Update the application and render
		Game.Update(DeltaTime);
		Game.Render();

		//Update the window display
		Window.display();


	}

	return 0;
}