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

#include "glcube.h"

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {

    class Cube : public GLCube {

    public:
        Cube(Point startPoint, Dimension dimension);
        virtual ~Cube();
        void draw();
        void setTopTextureId(GLuint textureId);
        void setBottomTextureId(GLuint textureId);
        void setLeftTextureId(GLuint textureId);
        void setRightTextureId(GLuint textureId);
        void setFrontTextureId(GLuint textureId);
        void setBackTextureId(GLuint textureId);

    private:
        GLuint topTextureId;
        GLuint bottomTextureId;
        GLuint leftTextureId;
        GLuint rightTextureId;
        GLuint frontTextureId;
        GLuint backTextureId;
        bool topTexture;
        bool bottomTexture;
        bool leftTexture;
        bool rightTexture;
        bool frontTexture;
        bool backTexture;
    };
    
}


