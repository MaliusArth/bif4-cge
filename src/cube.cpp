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
    }

    void Cube::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        
        // top and bottom
        this->setColor(0.3f, 1.0f, 1.0f);
        if(this->topTextureId == NULL){
            this->drawTop();
        } else {
            this->drawTop(this->topTextureId);
        }

        if(this->bottomTextureId == NULL){
            this->drawBottom();
        } else {
            this->drawTop(this->bottomTextureId);
        }

        // left and right
        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->leftTextureId == NULL){
            this->drawLeftSide();
        } else {
            this->drawLeftSide(this->leftTextureId);
        }

        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->rightTextureId == NULL){
            this->drawRightSide();
        } else {
            this->drawRightSide(this->rightTextureId);
        }
        
        // front and back
        this->setColor(0.0f, 1.0f, 1.0f);
        if(this->frontTextureId == NULL){
            this->drawFrontSide();
        } else {
            this->drawFrontSide(this->frontTextureId);
        }

        if(this->backTextureId == NULL){
            this->drawBackSide();
        } else {
            this->drawBackSide(this->backTextureId);
        }
        
        glPopMatrix();
    }
    

    void Cube::setTopTextureId ( GLuint textureId ) {
        this->topTextureId = textureId;
    }

    void Cube::setBackTextureId ( GLuint textureId ) {
        this->backTextureId = textureId;
    }

    void Cube::setBottomTextureId ( GLuint textureId ) {
        this->bottomTextureId = textureId;
    }

    void Cube::setFrontTextureId ( GLuint textureId ) {
        this->frontTextureId = textureId;
    }

    void Cube::setRightTextureId ( GLuint textureId ) {
        this->rightTextureId = textureId;
    }

    void Cube::setLeftTextureId ( GLuint textureId ) {
        this->leftTextureId = textureId;
    }
    
    Cube::~Cube() {

    }
    
}



