#include "InputManager.h"
#include <utility>

constexpr int A_SPEED = -2;
constexpr int D_SPEED = 2;
constexpr int W_SPEED = -2;
constexpr int S_SPEED = 2;

InputManager::~InputManager()
{
}

void InputManager::HandleInput()
{
	auto k = m_event.key.keysym.sym;
	if (SDL_KEYUP == m_event.type)
	{
		if (k == SDLK_a) 
		{
			if (xInput[0] == A_SPEED) xInput[0] = xInput[1];
			xInput[1] = 0;
			a_down = false;
		}
		else if (k == SDLK_d) 
		{
			if (xInput[0] == D_SPEED) xInput[0] = xInput[1];
			xInput[1] = 0;
			d_down = false;
		}
		else if (k == SDLK_w) 
		{
			if (yInput[0] == W_SPEED) yInput[0] = yInput[1];
			yInput[1] = 0;
			w_down = false;
		}
		else if (k == SDLK_s) 
		{
			if (yInput[0] == S_SPEED) yInput[0] = yInput[1];
			yInput[1] = 0;
			s_down = false;
		}
	} 
	else if (SDL_KEYDOWN == m_event.type)
	{
		if (k == SDLK_a) 
		{
			if (!a_down) // if A wasn't already down.
			{
				xInput[1] = xInput[0];
				xInput[0] = A_SPEED;
				a_down = true;
			}
		}
		else if (k == SDLK_d) 
		{
			if (!d_down) // if D wasn't already down.
			{
				xInput[1] = xInput[0];
				xInput[0] = D_SPEED;
				d_down = true;
			}
		}
		else if (k == SDLK_w) 
		{
			if (!w_down) // if A wasn't already down.
			{
				yInput[1] = yInput[0];
				yInput[0] = W_SPEED;
				w_down = true;
			}
		}
		else if (k == SDLK_s) 
		{
			if (!s_down) // if D wasn't already down.
			{
				yInput[1] = yInput[0];
				yInput[0] = S_SPEED;
				s_down = true;
			}
		}
	}
}

int InputManager::GetXInput()
{
	return xInput[0];
}

int InputManager::GetYInput()
{
	return yInput[0];
}