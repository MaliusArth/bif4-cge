/*
 *  WordGL                                                        *
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


#include "point.h"

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {
    
    Point::Point(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord) {
        this->xCoord = xCoord;
        this->yCoord = yCoord;
        this->zCoord = zCoord;
    }

    GLfloat Point::getXCoord() {
        return this->xCoord;
    }

    GLfloat Point::getYCoord() {
        return this->yCoord;
    }

    GLfloat Point::getZCoord() {
        return this->zCoord;
    }


    Point::~Point() {

    }

}
