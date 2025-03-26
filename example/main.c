/*
	This file is part of AuriText.

	AuriText is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	AuriText is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with AuriText.
	If not, see <https://www.gnu.org/licenses/>.
*/

#include <string.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../auriText.h"
#include "comIO.h"

#define RENDER_WIDTH 640
#define RENDER_HEIGHT 480

char running = 1;

int main() {
	char auriTextVersion[50];
	
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
		
		SDL_CreateTextureFromSurface(renderer, IMG_ReadXPMFromArray((char **)font_comIO))
	)) {
		return 1;
	}
	
	strcpy(auriTextVersion, "libAuriText v");
	strcat(auriTextVersion, auriText_version());
	
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
			AURITEXT_CENTER,
			auriTextVersion,
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) - 192,
			2.0f, 2.0f,
			
			0xFF, 0xFF, 0xFF, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"AuriText Example Program",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) - 152,
			2.0f, 2.0f,
			
			0xFF, 0xFF, 0xFF, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"Red",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) - 104,
			5.0f, 5.0f,
			
			0xFF, 0x00, 0x00, 0xFF
		);

		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"Green",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) - 40,
			5.0f, 5.0f,
			
			0x00, 0xFF, 0x00, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"Blue",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) + 24,
			5.0f, 5.0f,
			
			0x00, 0x00, 0xFF, 0xFF
		);
		
		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"Alpha - 128",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) + 88,
			5.0f, 5.0f,
			
			0xFF, 0xFF, 0xFF, 0x80
		);

		auriText_render(
			renderer,
			
			&comIO,
			AURITEXT_CENTER,
			"Alpha - 64",
			
			(float)RENDER_WIDTH / 2, (float)(RENDER_HEIGHT / 2) + 152,
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