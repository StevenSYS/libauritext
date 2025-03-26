/*
	This file is part of AuriText-SDL2.

	AuriText-SDL2 is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	AuriText-SDL2 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with AuriText.
	If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __AURITEXT__
#define __AURITEXT__

#ifdef __cplusplus
extern "C" {
#endif

struct SDL_Renderer;
struct SDL_Texture;

enum auriText_align {
	AURITEXT_LEFT,
	AURITEXT_CENTER,
	AURITEXT_RIGHT
};

enum auriText_errors {
	AURITEXT_NOERROR,
	AURITEXT_FONT_INVALID,
	AURITEXT_STRING_EMPTY,
	AURITEXT_STRING_TOOLONG
};

typedef struct {
	SDL_Texture *fontSheet;
	unsigned short size[2];
} font_t;

const char *auriText_version();

enum auriText_errors auriText_loadFont(
	SDL_Renderer *renderer,
	
	font_t *font,
	
	const unsigned char width,
	const unsigned char height,
	
	SDL_Texture *fontSheet
);

enum auriText_errors auriText_render(
	SDL_Renderer *renderer,
	
	const font_t *font,
	const enum auriText_align align,
	const char *text,
	
	short x, short y,
	char scaleX, char scaleY,
	
	const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha
);

#ifdef __cplusplus
}
#endif

#endif