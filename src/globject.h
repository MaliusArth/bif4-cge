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


#pragma once

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

#include "point.h"
#include "dimension.h"
#include "textureloader.h"

namespace WordGL {

    class GLObject {

    public:
        GLObject();
        virtual ~GLObject();
        void setColor(GLfloat red, GLfloat green, GLfloat blue);

    protected:
        void setCoordsDimension(Point startPoint, Dimension dimension);
        void move(GLfloat xCoord, GLfloat yCoord, GLfloat zCoord);
        static TextureLoader textureLoader;
        GLfloat startX;
        GLfloat startY;
        GLfloat startZ;
        GLfloat width;
        GLfloat height;
        GLfloat depth;
        
    };

    
}