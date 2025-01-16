/*
	This file is part of libAuriText.

	libAuriText is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	libAuriText is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with libAuriText.
	If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "auriText.h"

#define LIBRARY_NAME "AuriText"
#define LIBRARY_VERSION "1.0"

void auriText_getInfo() {
	printf(LIBRARY_NAME" v"LIBRARY_VERSION"\n");
	return;
}

bool auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	const char *fontSheet
) {
	if (fopen(fontSheet, "r") == NULL) {
		char errorMessage[255] = { 0 };
		
		strcat(errorMessage, "\"");
		strcat(errorMessage, fontSheet);
		strcat(errorMessage, "\" doesn't exist");
		
		printf("ERROR: %s\n", errorMessage);
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR: Font Sheet Missing", errorMessage, NULL);
		return true;
	}
	
	font->size[0] = width;
	font->size[1] = height;
	
	font->fontSheet = IMG_LoadTexture(renderer, fontSheet);
	SDL_SetTextureScaleMode(font->fontSheet, SDL_SCALEMODE_NEAREST);
	return false;
}

void auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	
	const unsigned char red, const unsigned char green, const unsigned char blue
) {
	char offset[2] = { 0, 0 };
	unsigned char letter = 0;
	
	if (strlen(text) > 0 && strlen(text) < 255) {
		if (align == RIGHT) {
			x -= strlen(text) * font->size[0];
		}
		for (unsigned short i = 0; i < strlen(text); i++) {
			switch (text[i]) {
				case 32: /* Space */
					offset[0]++;
					break;
				default:
					if (text[i] < 33 || text[i] > 126) {
						letter = 0;
					} else {
						letter = text[i] - 32;
					}
					SDL_FRect letterCrop = { letter * font->size[0], 0, font->size[0], font->size[1] };
					SDL_FRect letterRect = { x + offset[0] * font->size[0], y + offset[1] * font->size[1], font->size[0], font->size[1] };
					SDL_SetTextureColorMod(font->fontSheet, red, green, blue);
					SDL_RenderTexture(renderer, font->fontSheet, &letterCrop, &letterRect);
					offset[0]++;
					break;
			}
		}
	}
}