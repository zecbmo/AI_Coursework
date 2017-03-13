#pragma once


#include <windows.h>
#include <stdio.h>
#include <string>

class DebugSystem
{
public:
	DebugSystem() {};
	~DebugSystem() {};

	inline DebugSystem* Instance() { DebugSystem* Instance = this; return Instance; };

protected: 

	void ErrorMessage(std::string message, float value, bool destroy_window = true);
	void ErrorMessage(std::string message, int value, bool destroy_window = true);
	void ErrorMessage(std::string message, bool destroy_window = true);
	
	void Log();
};

