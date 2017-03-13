#include "DebugSystem.h"

//Declare static vars


 sf::Clock DebugSystem::m_DebugClock;
 sf::Font DebugSystem::m_Font;
 std::list<sf::Text*> DebugSystem::m_TextList;
 std::list<TimedMessage*> DebugSystem::m_MessageList;


//Message "Box" settings
 int DebugSystem::m_MessageBoxPosX;
 int DebugSystem::m_MessageBoxPosY;



void DebugSystem::Init(std::string FontFileName, int MessageBoxPosX, int MessageBoxPosY)
{
	//if the file name is not found throw error
	if (!m_Font.loadFromFile(FontFileName))
	{
		ErrorMessageWithID(FontFileName, "Unable to load Font in DebugUI");
	}

	m_MessageBoxPosX = MessageBoxPosX;
	m_MessageBoxPosY = MessageBoxPosY;
}

void DebugSystem::ErrorMessage(std::string message, float value, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, " %s : %.2f", message.c_str(), value);
	MessageBoxA(NULL, buffer, "Error!", MB_OK);
	

	if (destroy_window)
	{
		exit(1);
	}
}

void DebugSystem::ErrorMessage(std::string message, int value, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, " %s : %d", message.c_str(), value);
	MessageBoxA(NULL, buffer, "Error!", MB_OK);


	if (destroy_window)
	{
		exit(1);
	}
}

void DebugSystem::ErrorMessage(std::string message, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, "%s", message.c_str());
	MessageBoxA(NULL, buffer, "Error!", MB_OK);


	if (destroy_window)
	{
		exit(1);
	}
}
void DebugSystem::ErrorMessageWithID(std::string id, std::string message, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, "%s: %s", id.c_str(), message.c_str());
	MessageBoxA(NULL, buffer, "Error!", MB_OK);

	if (destroy_window)
	{
		//DestroyWindow(GetActiveWindow());
		exit(1);
	}
}

void DebugSystem::Log(std::string Message, DebugColour Colour, float TimeDelay)
{
	std::cout << Message << std::endl;

	sf::Time CurrentTime = m_DebugClock.getElapsedTime();

	sf::Time DeleteTime = sf::seconds(CurrentTime.asSeconds() + TimeDelay);

	sf::Text Text;
	Text.setFont(m_Font);
	Text.setString(Message);
	Text.setScale(FONT_SCALE, FONT_SCALE);
	//NewText->setPosition(sf::Vector2f(XPos, YPos));

	switch (Colour)
	{
	case kWhiteColour:
		Text.setFillColor(sf::Color(255, 255, 255, 255));
		break;
	case kRedColour:
		Text.setFillColor(sf::Color(255, 0, 0, 255));
		break;
	case kYellowColour:
		Text.setFillColor(sf::Color(255, 255, 0, 255));
		break;
	case kBlueColour:
		Text.setFillColor(sf::Color(0, 0, 255, 255));
		break;
	default:
		break;
	}


	TimedMessage* NewMessage = new TimedMessage(DeleteTime, Text);
	m_MessageList.push_front(NewMessage);
}

void DebugSystem::DisplayOnDebugScreen(std::string String, int XPos, int YPos, DebugColour Colour)
{

	sf::Text* NewText = new sf::Text();

	NewText->setFont(m_Font);
	NewText->setString(String);
	NewText->setPosition(sf::Vector2f((float)XPos, (float)YPos));
	NewText->setScale(FONT_SCALE, FONT_SCALE);

	switch (Colour)
	{
	case kWhiteColour:
		NewText->setFillColor(sf::Color(255, 255, 255, 255));
		break;
	case kRedColour:
		NewText->setFillColor(sf::Color(255, 0, 0, 255));
		break;
	case kYellowColour:
		NewText->setFillColor(sf::Color(255, 255, 0, 255));
		break;
	case kBlueColour:
		NewText->setFillColor(sf::Color(0, 0, 255, 255));
		break;
	default:
		break;
	}

	m_TextList.push_back(NewText);
}

void DebugSystem::Update()
{
	for (auto iter = m_MessageList.begin(); iter != m_MessageList.end(); /**nothing*/)
	{
		if ((*iter)->m_DeleteTime < m_DebugClock.getElapsedTime())
		{
			iter = m_MessageList.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void DebugSystem::Render(sf::RenderWindow * Window)
{
	if (!m_MessageList.empty())
	{
		float ypos = (float)m_MessageBoxPosY;

		for (auto iter : m_MessageList)
		{
			iter->m_Message.setPosition((float)m_MessageBoxPosX, ypos);
			Window->draw(iter->m_Message);
			ypos -= (PARAGRAH_SPACING * FONT_SCALE);
		}

	}

	for (auto iter : m_TextList)
	{
		Window->draw(*iter);
	}

	m_TextList.clear();
}

