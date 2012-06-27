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



#include "globject.h"
#include "textureloader.h"
#include <string>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {

    TextureLoader GLObject::textureLoader = TextureLoader( std::string("resources/textures/"));

    GLObject::GLObject() {

    }

    void GLObject::setCoordsDimension ( Point startPoint, Dimension dimension ) {
        this->startX = startPoint.getXCoord();
        this->startY = startPoint.getYCoord();
        this->startZ = startPoint.getZCoord();
        this->width = dimension.getWidth();
        this->depth = dimension.getDepth();
        this->height = dimension.getHeight();
    }

    void GLObject::setColor ( GLfloat red, GLfloat green, GLfloat blue ) {
        glColor3f(red, green, blue);
    }

    void GLObject::move ( GLfloat xCoord, GLfloat yCoord, GLfloat zCoord) {
        glTranslatef(xCoord, yCoord, zCoord);
    }
    
    GLObject::~GLObject() {

    }

}