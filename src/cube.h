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
#include <string>

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
        virtual void draw();
        void setTopTextureId(std::string textureId);
        void setBottomTextureId(std::string textureId);
        void setLeftTextureId(std::string textureId);
        void setRightTextureId(std::string textureId);
        void setFrontTextureId(std::string textureId);
        void setBackTextureId(std::string textureId);

    private:
        std::string topTextureId;
        std::string bottomTextureId;
        std::string leftTextureId;
        std::string rightTextureId;
        std::string frontTextureId;
        std::string backTextureId;
        bool topTexture;
        bool bottomTexture;
        bool leftTexture;
        bool rightTexture;
        bool frontTexture;
        bool backTexture;
    };
    
}


