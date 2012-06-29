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
 * This class represents a structure of dimensions (width, height, depth) that
 * is used to pass it to globjects to tell them where and how they have to be
 * drawn
 */

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

#include "dimension.h"

namespace WordGL {

    /**
     * @param width the width of the object
     * @param height the height of the object
     * @param depth the depth of the object
     */
    Dimension::Dimension ( GLfloat width, GLfloat height, GLfloat depth ) {
        this->depth = depth;
        this->width = width;
        this->height = height;
    }


    GLfloat Dimension::getHeight() {
        return this->height;
    }

    GLfloat Dimension::getDepth() {
        return this->depth;
    }

    GLfloat Dimension::getWidth() {
        return this->width;
    }


    Dimension::~Dimension() {

    }

}