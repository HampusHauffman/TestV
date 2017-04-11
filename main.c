
//----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_net.h"
#include "SDL_image.h"
#include <windows.h>



//----------------------------------------------------------------------
void game_init(void);
void game_quit(void);

static struct {
	// define "attributes"
	SDL_bool running;

	// define "methods"
	void(*init)(void);
	void(*quit)(void);
} Game = {
	SDL_FALSE,
	game_init,
	game_quit
};

//----------------------------------------------------------------------
void game_init(void) {
	printf("game_init()\n\n");

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL error -> %sn", SDL_GetError());
		exit(1);
	}

	Game.running = SDL_TRUE;
}

//----------------------------------------------------------------------
void game_quit(void) {
	printf("game_quit()\n");
	SDL_Quit();
	Game.running = SDL_FALSE;
}

//----------------------------------------------------------------------
int main(int argc, char* argv[]) {

	Game.init();

	printf("running = %d\n", Game.running);

	while (Game.running) {
		Game.quit();
	}

	printf("running = %d\n", Game.running);

	Sleep(4000);

	return 0;
}