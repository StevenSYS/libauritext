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

#define LIBRARY_VERSION "1.2.3.1"

#define MAX_TEXTLENGTH 65535

#define ERROR_MESSAGES
#define ERROR_SDLMESSAGES

char *auriText_version() {
	return LIBRARY_VERSION;
}

enum auriText_errors auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	const char *fontSheet
) {
	if (fopen(fontSheet, "r") == NULL) {
		#if defined(ERROR_MESSAGES) || defined(ERROR_SDLMESSAGES)
		char errorMessage[255] = { 0 };
		
		strcat(errorMessage, "\"");
		strcat(errorMessage, fontSheet);
		strcat(errorMessage, "\" doesn't exist");
		#ifdef ERROR_MESSAGES
		fprintf(stderr, "ERROR: %s\n", errorMessage);
		#endif
		#ifdef ERROR_SDLMESSAGES
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR: libAuriText - Font Sheet Missing", errorMessage, NULL);
		#endif
		#endif
		return AURITEXT_FONT_MISSING;
	}
	
	font->size[0] = width;
	font->size[1] = height;
	
	font->fontSheet = IMG_LoadTexture(renderer, fontSheet);
	SDL_SetTextureScaleMode(font->fontSheet, SDL_SCALEMODE_NEAREST);
	return AURITEXT_NOERROR;
}

enum auriText_errors auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	float scaleX, float scaleY,
	
	const unsigned char red, const unsigned char green, const unsigned char blue
) {
	unsigned char letter = 0;
	
	if (strlen(text) > 0 && strlen(text) < MAX_TEXTLENGTH) {
		switch (align) {
			case LEFT:
				break;
			case CENTER:
				x -= (strlen(text) * (font->size[0] * scaleX)) / 2;
				break;
			case RIGHT:
				x -= strlen(text) * (font->size[0] * scaleX);
				break;
		}
		for (unsigned short i = 0; i < strlen(text); i++) {
			switch (text[i]) {
				case 32: /* Space */
					x += font->size[0] * scaleX;
					break;
				default:
					if (text[i] < 33 || text[i] > 126) {
						letter = 0;
					} else {
						letter = text[i] - 32;
					}
					SDL_FRect letterCrop = { (letter * font->size[0]), 0, font->size[0], font->size[1] };
					SDL_FRect letterRect = { x, y, font->size[0] * scaleX, font->size[1] * scaleY };
					SDL_SetTextureColorMod(font->fontSheet, red, green, blue);
					SDL_RenderTexture(renderer, font->fontSheet, &letterCrop, &letterRect);
					x += font->size[0] * scaleX;
					break;
			}
		}
	} else if (strlen(text) <= 0) {
		return AURITEXT_STRING_EMPTY;
	} else if (strlen(text) > MAX_TEXTLENGTH) {
		return AURITEXT_STRING_TOOLONG;
	}
	return AURITEXT_NOERROR;
}