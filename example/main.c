#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../auriText.h"
#include "comIO.h"

#define RENDER_WIDTH 640
#define RENDER_HEIGHT 480

char running = 1;

int main() {
	SDL_Event event;
	SDL_Window *window = SDL_CreateWindow(
		"AuriText Example Program",
		RENDER_WIDTH, RENDER_HEIGHT,
		0
	);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(
		window,
		"opengl"
	);
	
	SDL_SetRenderDrawColor(renderer, 0x00, 0x40, 0x00, 0x00);
	
	font_t comIO;
	if (auriText_loadFont(
		renderer,
		
		&comIO,
		
		8, 8,
		
		SDL_CreateTextureFromSurface(renderer, IMG_ReadXPMFromArray(font_comIO))
	)) {
		return 1;
	}
	
	while (running) {
		SDL_PollEvent(&event);
		SDL_RenderClear(renderer);
		
		switch (event.type) {
			case SDL_EVENT_QUIT:
				running = 0;
				break;
		}
		
		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"AuriText Example Program",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2) - 192,
			2.0f, 2.0f,
			
			0xFF, 0xFF, 0xFF, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"Red",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2) - 128,
			5.0f, 5.0f,
			
			0xFF, 0x00, 0x00, 0xFF
		);

		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"Green",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2) - 64,
			5.0f, 5.0f,
			
			0x00, 0xFF, 0x00, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"Blue",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2),
			5.0f, 5.0f,
			
			0x00, 0x00, 0xFF, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"Alpha - 128",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2) + 64,
			5.0f, 5.0f,
			
			0xFF, 0xFF, 0xFF, 0x80
		);

		auriText_render(
			renderer,
			
			&comIO,
			CENTER,
			"Alpha - 64",
			
			RENDER_WIDTH / 2, (RENDER_HEIGHT / 2) + 128,
			5.0f, 5.0f,
			
			0xFF, 0xFF, 0xFF, 0x40
		);
		
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}