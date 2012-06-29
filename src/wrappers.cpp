/**
 *  WordGL
 *  Copyright (C) 2012  Bernhard Posselt <bernhard.posselt@gmx.at>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Create wrapper functions for the object because we can not pass methods to
 * glut
 */

#include "wrappers.h"
#include "window.h"

namespace WordGL {

    void display_wrapper(){
        Window::getInstance()->display();
    }

	void keySpecial_wrapper(int key, int x, int y){
		Window::getInstance()->specialKeyPressed(key, x, y);
	}

    void resize_wrapper(int width, int height){
        Window::getInstance()->resize(width, height);
    }

    void keyPressed_wrapper(unsigned char key, int x, int y){
        Window::getInstance()->keyPressed(key, x, y);
    }

    void timer_wrapper(int value) {
        Window::getInstance()->redisplayTimer(value);
    }
    
}