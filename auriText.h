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

#ifndef __LIBAURITEXT__
#define __LIBAURITEXT__

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

enum auriText_align {
	LEFT,
	RIGHT
};

typedef struct {
	SDL_Texture *fontSheet;
	unsigned char size[2];
} font_t;

char *auriText_version();

bool auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	const char *fontSheet
);

void auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	
	const unsigned char red, const unsigned char green, const unsigned char blue
);

#endif