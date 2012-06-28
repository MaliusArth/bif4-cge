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

#include "globject.h"
#include <string>
#include "dimension.h"
#include "point.h"

namespace WordGL {

    class GLCube : public GLObject {

    public:
        GLCube(Point startPoint, Dimension dimension);
        virtual ~GLCube();
        virtual void draw();
        virtual void setTopTexture(std::string textureName);
        virtual void setBottomTexture(std::string textureName);
        virtual void setLeftTexture(std::string textureName);
        virtual void setRightTexture(std::string textureName);
        virtual void setFrontTexture(std::string textureName);
        virtual void setBackTexture(std::string textureName);

    protected:
        virtual void texturize(std::string textureName);
        virtual void drawBottom();
        virtual void drawBottom(std::string textureName);
        virtual void drawTop();
        virtual void drawTop(std::string textureName);
        virtual void drawFrontSide();
        virtual void drawFrontSide(std::string textureName);
        virtual void drawRightSide();
        virtual void drawRightSide(std::string textureName);
        virtual void drawBackSide();
        virtual void drawBackSide(std::string textureName);
        virtual void drawLeftSide();
        virtual void drawLeftSide(std::string textureName);

    private:
        std::string topTextureName;
        std::string bottomTextureName;
        std::string leftTextureName;
        std::string rightTextureName;
        std::string frontTextureName;
        std::string backTextureName;
        bool topTexture;
        bool bottomTexture;
        bool leftTexture;
        bool rightTexture;
        bool frontTexture;
        bool backTexture;
    };
   
}


