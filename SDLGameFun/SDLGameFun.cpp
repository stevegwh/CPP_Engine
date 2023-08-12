#include <iostream>
#include <SDL.h>
#include "Game.h"




// You must include the command line parameters for your main function to be recognized by SDL
int main(int argc, char** args) {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	// Initialize SDL. SDL_Init will return -1 if it fails.
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) 
	{
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	} 

	// Create our window
	window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN );
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// Make sure creating the window succeeded
	if ( !window ) 
	{
		std::cout << "Error creating window: " << SDL_GetError()  << std::endl;
		system("pause");
		// End the program
		return 1;
	}


	Game game(renderer);
	game.Run();
	

	// Destroy the window. This will also destroy the surface
	SDL_DestroyWindow( window );

	// Quit SDL
	SDL_Quit();
	
	// End the program
	return 0;
}