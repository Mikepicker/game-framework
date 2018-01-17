// Using SDL and standard IO
#ifdef LINUX
#include <SDL2/SDL.h>
#elif WIN
#include <SDL.h>
#endif
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

#include "framework.cpp"
#include "particles.cpp"

// Constants
onst double PI = 3.14159265;

// Textures
//SDL_Texture* texture;

// Font
TTF_Font* font = NULL;

// Enums
/*enum Enum {
  BLUE = 0,
  RED = 1
};*/

// Game entities
/*struct Entity {
  Sint32 integer;
  SDL_Texture* texture;
};*/

// Variables
// Entity entity;

// Quit game
bool quit = false;

// Game state
enum GameState {
  STATE_MENU,
  STATE_GAME
} gameState;

#include "game.cpp"

bool load() {

    // Loading success flag
    bool success = true;
    
    // Init font
    font = TTF_OpenFont("assets/PixelText.ttf", 32);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    }

    // Init textures
    // texture = loadTexture("assets/texture.png");

    return success;
}

void close() {

    //Free loaded image
    // SDL_DestroyTexture(texture);

    // Free font
    TTF_CloseFont(font);
    font = NULL;
}

// Game logic
void input(SDL_Event* e) {

}

void update() {

  Uint32 now = SDL_GetTicks();
}

void render() {

    // Clear screen
    SDL_RenderClear(renderer);

    // Bg color
    SDL_SetRenderDrawColor(renderer, 0x63, 0x9b, 0xff, 0xff);

    // Update the screen
    SDL_RenderPresent(renderer);
}

int main(Sint32 argc, char* args[]) {

	//Start up SDL and create window
	if(!initFramework()) {
		printf("Failed to initialize!\n");
	}
	else {
		// Load media
		if(!load()) {
			printf("Failed to load media!\n");
		}
		else {

      // Event handler
      SDL_Event e;

      Sint32 countedFrames = 0;

      // While application is running
      while(!quit) {

        // Handle events on queue
        while(SDL_PollEvent(&e) != 0) {

          // User requests quit
          if(e.type == SDL_QUIT) {
            quit = true;
          }

          input(&e);
        }

        float avgFPS = countedFrames / (SDL_GetTicks() / 1000.f);
        if(avgFPS > 2000000) {
          avgFPS = 0;
        }

        // Update game
        update();

        // Render game
        render();

        countedFrames++;
      }
    }
	}

	//Free resources and close SDL
	close();

	return 0;
}
