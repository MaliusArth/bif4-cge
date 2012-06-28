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



#include "glcube.h"
#include <string>
#include "dimension.h"
#include "point.h"

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {

    GLCube::GLCube(Point startPoint, Dimension dimension) {
        this->setCoordsDimension(startPoint, dimension);
        this->topTexture = false;
        this->bottomTexture = false;
        this->rightTexture = false;
        this->leftTexture = false;
        this->frontTexture = false;
        this->backTexture = false;
    }

    void GLCube::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);

        // top and bottom
        this->setColor(0.3f, 1.0f, 1.0f);
        if(this->topTexture){
            this->drawTop();
        } else {
            this->drawTop(this->topTextureName);
        }

        if(this->bottomTexture){
            this->drawBottom();
        } else {
            this->drawTop(this->bottomTextureName);
        }

        // left and right
        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->leftTexture){
            this->drawLeftSide();
        } else {
            this->drawLeftSide(this->leftTextureName);
        }

        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->rightTexture){
            this->drawRightSide();
        } else {
            this->drawRightSide(this->rightTextureName);
        }

        // front and back
        this->setColor(0.0f, 1.0f, 1.0f);
        if(this->frontTexture){
            this->drawFrontSide();
        } else {
            this->drawFrontSide(this->frontTextureName);
        }

        if(this->backTexture){
            this->drawBackSide();
        } else {
            this->drawBackSide(this->backTextureName);
        }

        glPopMatrix();
    }


    void GLCube::setTopTexture ( std::string textureName ) {
        this->topTexture = true;
        this->topTextureName = textureName;
    }

    void GLCube::setBottomTexture ( std::string textureName ) {
        this->bottomTexture = true;
        this->bottomTextureName = textureName;
    }

    void GLCube::setBackTexture ( std::string textureName ) {
        this->backTexture = true;
        this->backTextureName = textureName;
    }

    void GLCube::setFrontTexture ( std::string textureName ) {
        this->frontTexture = true;
        this->frontTextureName = textureName;
    }

    void GLCube::setRightTexture ( std::string textureName ) {
        this->rightTexture = true;
        this->rightTextureName = textureName;
    }

    void GLCube::setLeftTexture ( std::string textureName ) {
        this->leftTexture = true;
        this->leftTextureName = textureName;
    }
    
    void GLCube::drawBottom(std::string textureName) {
        TextureLoader* textureLoader = TextureLoader::getInstance();
        GLuint textureId = textureLoader->getTextureId(textureName);
        this->drawBottom();
    }
    
    void GLCube::drawBottom() {
        glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, this->depth);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, this->depth);
        glEnd();
    }

    void GLCube::drawTop(std::string textureName) {
        // TODO: set texture
        this->drawTop();
    }
    
    void GLCube::drawTop() {
        glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f+this->height, this->depth);
        glVertex3f(0.0f, 0.0f+this->height, 0.0f);
        glVertex3f(this->width, 0.0f+this->height, 0.0f);
        glVertex3f(this->width, 0.0f+this->height, this->depth);
        glEnd();
    }

    void GLCube::drawFrontSide(std::string textureName) {
        // TODO: set texture
        this->drawFrontSide();
    }
    
    void GLCube::drawFrontSide() {
        glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(this->width, this->height, 0.0f);
        glVertex3f(0.0f, this->height, 0.0f);
        glVertex3f(this->width, 0.0f, 0.0f);
        glEnd();
    }

    void GLCube::drawBackSide(std::string textureName) {
        // TODO: set texture
        this->drawBackSide();
    }

    
    void GLCube::drawBackSide() {
        glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, this->depth);
        glVertex3f(this->width, this->height, this->depth);
        glVertex3f(0.0f, this->height, this->depth);
        glVertex3f(this->width, 0.0f, this->depth);
        glEnd();
    }

    void GLCube::drawLeftSide(std::string textureName) {
        // TODO: set texture
        this->drawLeftSide();
    }
    
    void GLCube::drawLeftSide() {
        glBegin(GL_QUADS);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, this->depth);
        glVertex3f(0.0f, this->height, this->depth);
        glVertex3f(0.0f, this->height, 0.0f);
        glEnd();
    }

    void GLCube::drawRightSide(std::string textureName) {
        // TODO: set texture
        this->drawRightSide();
    }
    
    void GLCube::drawRightSide() {
        glBegin(GL_QUADS);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, this->depth);
        glVertex3f(this->width, this->height, this->depth);
        glVertex3f(this->width, this->height, 0.0f);
        glEnd();
    }

    GLCube::~GLCube() {

    }

    
}