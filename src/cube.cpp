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

#include "cube.h"

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {
    
    Cube::Cube ( Point startPoint, Dimension dimension ) {
        this->setCoordsDimension(startPoint, dimension);
        this->topTexture = false;
        this->bottomTexture = false;
        this->rightTexture = false;
        this->leftTexture = false;
        this->frontTexture = false;
        this->backTexture = false;
    }

    void Cube::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        
        // top and bottom
        this->setColor(0.3f, 1.0f, 1.0f);
        if(this->topTexture){
            this->drawTop();
        } else {
            this->drawTop(this->topTextureId);
        }

        if(this->bottomTexture){
            this->drawBottom();
        } else {
            this->drawTop(this->bottomTextureId);
        }

        // left and right
        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->leftTexture){
            this->drawLeftSide();
        } else {
            this->drawLeftSide(this->leftTextureId);
        }

        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->rightTexture){
            this->drawRightSide();
        } else {
            this->drawRightSide(this->rightTextureId);
        }
        
        // front and back
        this->setColor(0.0f, 1.0f, 1.0f);
        if(this->frontTexture){
            this->drawFrontSide();
        } else {
            this->drawFrontSide(this->frontTextureId);
        }

        if(this->backTexture){
            this->drawBackSide();
        } else {
            this->drawBackSide(this->backTextureId);
        }
        
        glPopMatrix();
    }
    

    void Cube::setTopTextureId ( GLuint textureId ) {
        this->topTexture = true;
        this->topTextureId = textureId;
    }

    void Cube::setBottomTextureId ( GLuint textureId ) {
        this->bottomTexture = true;
        this->bottomTextureId = textureId;
    }
    
    void Cube::setBackTextureId ( GLuint textureId ) {
        this->backTexture = true;
        this->backTextureId = textureId;
    }

    void Cube::setFrontTextureId ( GLuint textureId ) {
        this->frontTexture = true;
        this->frontTextureId = textureId;
    }

    void Cube::setRightTextureId ( GLuint textureId ) {
        this->rightTexture = true;
        this->rightTextureId = textureId;
    }

    void Cube::setLeftTextureId ( GLuint textureId ) {
        this->leftTexture = true;
        this->leftTextureId = textureId;
    }
    
    Cube::~Cube() {

    }
    
}



