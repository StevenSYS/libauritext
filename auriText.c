/*
	This file is part of AuriText-SDL2.

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
#include <SDL2/SDL.h>

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
	if (!fontSheet) {
		#if defined(ERROR_MESSAGES_STDERR) || defined(ERROR_MESSAGES_SDL)
		const char *errorMessage = "Font sheet texture is invalid";
		
		#ifdef ERROR_MESSAGES_STDERR
		fprintf(stderr, "ERROR: %s\n", errorMessage);
		#endif
		#ifdef ERROR_MESSAGES_SDL
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR: AuriText-SDL2 - Invalid Font Sheet Texture", errorMessage, NULL);
		#endif
		#endif
		return AURITEXT_FONT_INVALID;
	}
	
	font->size[0] = width;
	font->size[1] = height;
	
	font->fontSheet = fontSheet;
	SDL_SetTextureScaleMode(font->fontSheet, SDL_ScaleModeNearest);
	return AURITEXT_NOERROR;
}

enum auriText_errors auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	char scaleX, char scaleY,
	
	const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha
) {
	unsigned char letter = 0;
	
	if (strlen(text) > 0 && strlen(text) < MAX_TEXTLENGTH) {
		switch (align) {
			case AURITEXT_LEFT:
				break;
			case AURITEXT_CENTER:
				x -= (strlen(text) * (font->size[0] * scaleX)) / 2;
				break;
			case AURITEXT_RIGHT:
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
					SDL_Rect letterCrop = { letter * font->size[0], 0, font->size[0], font->size[1] };
					SDL_Rect letterRect = { x, y, font->size[0] * scaleX, font->size[1] * scaleY };
					SDL_SetTextureColorMod(font->fontSheet, red, green, blue);
					SDL_SetTextureAlphaMod(font->fontSheet, alpha);
					SDL_RenderCopy(renderer, font->fontSheet, &letterCrop, &letterRect);
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