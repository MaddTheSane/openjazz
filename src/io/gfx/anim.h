
/*
 *
 * anim.h
 *
 * 26th July 2009: Created anim.h from parts of sprite.h
 *
 * Part of the OpenJazz project
 *
 *
 * Copyright (c) 2005-2009 Alister Thomson
 *
 * OpenJazz is distributed under the terms of
 * the GNU General Public License, version 2.0
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef _ANIM_H
#define _ANIM_H


#include <SDL/SDL.h>


// Classes

class Sprite;

class Anim {

	private:
		Sprite        *sprites[19];
		signed char    xOffset;
		signed char    yOffset;
		signed char    xOffsets[19];
		signed char    yOffsets[19];
		unsigned char  frames;       // Number of frames
		unsigned char  frame;        // Current frame

	public:
		Anim                ();
		~Anim               ();

		void setData        (int amount, signed char x, signed char y);
		void setFrame       (int nextFrame, bool looping);
		void setFrameData   (Sprite *frameSprite, signed char x, signed char y);
		int  getWidth       ();
		int  getHeight      ();
		void draw           (int x, int y);
		void setPalette     (SDL_Color *palette, int start, int amount);
		void flashPalette   (int index);
		void restorePalette ();

};

#endif
