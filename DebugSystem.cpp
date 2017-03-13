#include "DebugSystem.h"

void DebugSystem::ErrorMessage(std::string message, float value, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, " %s : %.2f", message.c_str(), value);
	MessageBoxA(NULL, buffer, "Idiot Programmer", MB_OK);


	if (destroy_window)
	{
		exit(1);
	}
}

void DebugSystem::ErrorMessage(std::string message, int value, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, " %s : %.2f", message.c_str(), value);
	MessageBoxA(NULL, buffer, "Idiot Programmer", MB_OK);


	if (destroy_window)
	{
		exit(1);
	}
}

void DebugSystem::ErrorMessage(std::string message, bool destroy_window)
{
	char buffer[255];
	sprintf_s(buffer, "%s", message.c_str());
	MessageBoxA(NULL, buffer, "Idiot Programmer", MB_OK);


	if (destroy_window)
	{
		exit(1);
	}
}
