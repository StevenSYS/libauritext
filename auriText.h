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

#ifndef __AURITEXT__
#define __AURITEXT__

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

enum auriText_align {
	LEFT,
	RIGHT
};

enum auriText_errors {
	AURITEXT_NOERROR,
	AURITEXT_FONT_MISSING,
	AURITEXT_STRING_EMPTY,
	AURITEXT_STRING_TOOLONG
};

typedef struct {
	SDL_Texture *fontSheet;
	unsigned char size[2];
} font_t;

char *auriText_version();

enum auriText_errors auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	const char *fontSheet
);

enum auriText_errors auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	char scaleX, char scaleY,
	
	const unsigned char red, const unsigned char green, const unsigned char blue
);

#endif