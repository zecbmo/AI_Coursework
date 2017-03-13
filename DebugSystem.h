#pragma once


#include <windows.h>
#include <stdio.h>
#include <string>
#include "SFML\Graphics.hpp"
#include <list>
#include <iostream>

#define LOG_DELETE_DELAY 2.5
#define PARAGRAH_SPACING 25
#define FONT_SCALE 0.5f

/**	THE DEBUG CLASS
*
*	The Debug class was created to help display Text on the screen
*	Rather than creating alot of text objects and worrying about Wheter they should render or not
*	The debug class will manage this for us with the help of static functions.
*	Add Text to the debug screen should be done in the init functions (WARNING: NEVER IN WHILE LOOP)
*	It will return a pointer to a text object that you can manage
*	This is pushed on to a list of Text objects that the debug class will render
*
*
*	Messages will be strings that appear on screen and delete after a small moment of time - can be added in main game loop
*
*/

/**
*	The Text Colour
*/
enum DebugColour { kWhiteColour, kRedColour, kYellowColour, kBlueColour };


/**
*	Timed Message Struct Keeps track of messages to appear in the "Log"
*	After an elpased time will remove them and no longer be displayed
*/
struct TimedMessage
{
	TimedMessage(sf::Time DeleteTime, sf::Text Message)
	{
		m_DeleteTime = DeleteTime;
		m_Message = Message;
	}
	sf::Time m_DeleteTime;
	sf::Text m_Message;
};



class DebugSystem
{
public:
	DebugSystem() {};
	~DebugSystem() { m_TextList.clear();	m_MessageList.clear(); };

	/**
	*	Initialsier
	*
	*	@param Font File name for the font to be used
	*   @param the positon of the message box x/y
	*/
	static void Init(std::string FontFileName, int MessageBoxPosX, int MessageBoxPosY);


	/**
	*	A coolection of Pop up error messages that can be used in the event of serious errors.
	*
	*	Helpful for debugging everything.
	*/
	static void ErrorMessage(std::string message, float value, bool destroy_window = true);
	static void ErrorMessage(std::string message, int value, bool destroy_window = true);
	static void ErrorMessage(std::string message, bool destroy_window = true);
	static void ErrorMessageWithID(std::string id, std::string message, bool destroy_window= true);
	


	/**
	*	Log will display a message on screen for a given time and log in the console.
	*
	*	@param The message to be displayd
	*	@param The Colour
	*	@param the time the message will stay on the screen - Set to default if not overriden
	*/
	static void Log(std::string Message, DebugColour Colour = kWhiteColour, float TimeDelay = LOG_DELETE_DELAY);



	/**
	*	Display On Debug Screen is a funciton that will display text on the screen at a given position
	*	Helps to keep track of paramaters that need constant watching/updating
	*
	*	@param The Text to be displayed
	*	@param the x positon of the text display
	*	@param the y positon of the text display
	*	@param the Colour of the Text
	*/
	static void DisplayOnDebugScreen(std::string String, int XPos, int YPos, DebugColour Colour = kWhiteColour);


	/**
	*	Updates the text on screen funciton
	*/

	static void Update();
	/**
	*	Render funciton
	*
	*	@param Pointer to the SFML window
	*/
	static void Render(sf::RenderWindow* Window);


	/**
	*	Static Members 
	*
	*	Used to help with time and displaying messages
	*
	*/

	static  sf::Clock m_DebugClock;
	static  sf::Font m_Font;
	static  std::list<sf::Text*> m_TextList;
	static  std::list<TimedMessage*> m_MessageList;

	/**
	*	Message box settings
	*/
	static int m_MessageBoxPosX;
	static int m_MessageBoxPosY;

};

