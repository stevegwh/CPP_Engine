#include "Game.h"
#include <iostream>
#include "Player.h"
#include "InputManager.h"
#include "Observer.h"
#include "GEvent.h"


struct Clock
{
    uint32_t last_tick_time = 0;
    uint32_t delta = 0;

    void tick()
    {
        uint32_t tick_time = SDL_GetTicks();
        delta = tick_time - last_tick_time;
        last_tick_time = tick_time;
    }
};

Game::Game(SDL_Renderer* renderer)
{
	this->renderer = renderer;

}

Game::~Game() = default;



void Game::Run()
{
	Clock clock;
	
	SDL_Event event;
	InputManager inputManager(event);
	Player player;

	const std::function<void()> bar = [ObjectPtr = &player] { ObjectPtr->EventTest(); };
	Observer observer(bar);
	Observer* observer_ptr = &observer;
	GEvent gevent;
	gevent.Subscribe(observer_ptr);
	gevent.InvokeAllEvents();
	gevent.Unsubscribe(observer_ptr);
	gevent.InvokeAllEvents();
	while (true)
	{
		clock.tick();
		// Update
		if (SDL_PollEvent(&event))
		{
			if (SDL_QUIT == event.type)
			{
				break;
			}
			inputManager.HandleInput();
		}


		player.SetPosition(
			player.GetPosition().x + inputManager.GetXInput(),
			player.GetPosition().y + inputManager.GetYInput()
		);

		player.Update(clock.delta);



		SDL_RenderClear(renderer);
		Draw();
		player.Draw(renderer);


	}
}

void Game::Draw() const
{
	// Draw
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, NULL);
	for (const auto& e : entities)
	{
		e->Draw(renderer);
	}
}
