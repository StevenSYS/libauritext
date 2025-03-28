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

#define ERROR_MESSAGES_STDERR
#define ERROR_MESSAGES_SDL

#ifdef ERROR_MESSAGES_STDERR
#include <stdio.h>
#endif
#include <SDL3/SDL.h>

#include "auriText.h"

#define LIBRARY_VERSION "1.3-pre"

#define MAX_TEXTLENGTH 65535

const char *auriText_version() {
	return LIBRARY_VERSION;
}

enum auriText_errors auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	SDL_Texture *fontSheet
) {
	if (fontSheet == NULL) {
		#if defined(ERROR_MESSAGES_STDERR) || defined(ERROR_MESSAGES_SDL)
		const char *errorMessage = "Font sheet texture is invalid";
		
		#ifdef ERROR_MESSAGES_STDERR
		fprintf(stderr, "ERROR: %s\n", errorMessage);
		#endif
		#ifdef ERROR_MESSAGES_SDL
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR: AuriText - Invalid Font Sheet Texture", errorMessage, NULL);
		#endif
		#endif
		return AURITEXT_FONT_INVALID;
	}
	
	font->size[0] = (float)width;
	font->size[1] = (float)height;
	
	font->fontSheet = fontSheet;
	SDL_SetTextureScaleMode(font->fontSheet, SDL_SCALEMODE_NEAREST);
	return AURITEXT_NOERROR;
}

enum auriText_errors auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	float x, float y,
	float scaleX, float scaleY,
	
	const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha
) {
	unsigned char character = 0;
	
	if (strlen(text) && strlen(text) < MAX_TEXTLENGTH) {
		switch (align) {
			case AURITEXT_CENTER:
				x -= (strlen(text) * (font->size[0] * scaleX)) / 2;
				break;
			case AURITEXT_RIGHT:
				x -= strlen(text) * (font->size[0] * scaleX);
				break;
			default: /* This is here so the compiler won't give a warning */
				break;
		}
		
		for (unsigned short i = 0; i < strlen(text); i++) {
			if (text[i] != ' ') {
				if (text[i] < 33 || text[i] > 126) {
					character = 0;
				} else {
					character = text[i] - 32;
				}
				
				SDL_FRect cropRect = { character * font->size[0], 0, font->size[0], font->size[1] };
				SDL_FRect sizeRect = { x, y, font->size[0] * scaleX, font->size[1] * scaleY };
				SDL_SetTextureColorMod(font->fontSheet, red, green, blue);
				SDL_SetTextureAlphaMod(font->fontSheet, alpha);
				SDL_RenderTexture(renderer, font->fontSheet, &cropRect, &sizeRect);
			}
			
			x += font->size[0] * scaleX;
		}
	} else if (!strlen(text)) {
		return AURITEXT_STRING_EMPTY;
	} else if (strlen(text) > MAX_TEXTLENGTH) {
		return AURITEXT_STRING_TOOLONG;
	}
	
	return AURITEXT_NOERROR;
}