#pragma once
#include <SDL.h>
#include <functional>
#include <vector>
class InputManager
{
private:
	bool a_down = false;
	bool d_down = false;
	bool w_down = false;
	bool s_down = false;
	int xInput[2];
	int yInput[2];
	const SDL_Event& m_event;
public:
	// Array of callbacks/actions
	InputManager(const SDL_Event& event):m_event(event), xInput { 0, 0 }, yInput { 0, 0 }
	{};
	~InputManager();
	void HandleInput();
	int GetXInput();
	int GetYInput();
};

