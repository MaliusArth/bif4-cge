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

#include <iostream>		//debug: cout
#include <string>

#include "dimension.h"
#include "point.h"
#include "glcube.h"

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
		
        // top
		glPushMatrix();
        this->setColor(0.3f, 1.0f, 1.0f);
        if(this->topTexture){
            this->drawTop(this->topTextureName);
        } else {
            this->drawTop();
        }
        glPopMatrix();
		
		// bottom
		glPushMatrix();
		this->setColor(0.3f, 1.0f, 1.0f);
        if(this->bottomTexture){
            this->drawBottom(this->bottomTextureName);
        } else {
            this->drawTop();
		}
        glPopMatrix();
		
		// left
        glPushMatrix();
        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->leftTexture){
            this->drawLeftSide(this->leftTextureName);
        } else {
            this->drawLeftSide();
        }
        glPopMatrix();
		
		// right
		glPushMatrix();
        this->setColor(0.5f, 1.0f, 1.0f);
        if(this->rightTexture){
            this->drawRightSide(this->rightTextureName);
        } else {
            this->drawRightSide();
        }
        glPopMatrix();
		
		// front
		glPushMatrix();
        this->setColor(0.0f, 1.0f, 1.0f);
        if(this->frontTexture){
            this->drawFrontSide(this->frontTextureName);
        } else {
            this->drawFrontSide();
        }
        glPopMatrix();

		//back
		glPushMatrix();
        this->setColor(0.0f, 1.0f, 1.0f);
        if(this->backTexture){
            this->drawBackSide(this->backTextureName);
        } else {
            this->drawBackSide();
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
    
    void GLCube::drawBottom(std::string textureName) {		//TODO draws bottom with textures
        this->texturize(textureName);
        this->drawBottom();		//set boolean for textures
    }

    void GLCube::texturize ( std::string textureName ) {
        TextureLoader* textureLoader = TextureLoader::getInstance();
        GLuint textureId = textureLoader->getTextureId(textureName);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureId);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D,
		//				GL_TEXTURE_MIN_FILTER,
		//				GL_LINEAR_MIPMAP_LINEAR);
    }

    
    void GLCube::drawBottom() {	//boolean for if (set_bool) glTexCoord2f(...);
		glBegin(GL_QUADS);
		//x... rechts, y...rauf; z... vor
		glNormal3f(0.0f, 1.0f, 0.0f);
		
		glVertex3f(0.0f, 0.0f+this->height, this->depth);
        glVertex3f(0.0f, 0.0f+this->height, 0.0f);
        glVertex3f(this->width, 0.0f+this->height, 0.0f);
        glVertex3f(this->width, 0.0f+this->height, this->depth);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, 0.0f, 0.0f);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    void GLCube::drawTop(std::string textureName) {
        this->texturize(textureName);
        this->drawTop();
    }
    
    void GLCube::drawTop() {
// 		float _pos = 0.0f;		//The forward position relative to the floor
// 		const float FLOOR_TEXTURE_SIZE = this->depth - _pos; //The size of each "tile"
        glBegin(GL_QUADS);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, this->height, this->depth);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, this->height, this->depth);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		
		// 		glNormal3f(0.0f, 1.0f, 0.0f);
// 		glTexCoord2f(2000 / FLOOR_TEXTURE_SIZE, _pos / FLOOR_TEXTURE_SIZE);
// 		glVertex3f(0.0f, 0.0f, 0.0f);
// 		
// 		glTexCoord2f(2000 / FLOOR_TEXTURE_SIZE, (2000 + _pos) / FLOOR_TEXTURE_SIZE);
// 		glVertex3f(0.0f, 0.0f, this->depth);
// 		
// 		glTexCoord2f(0.0f, (2000 + _pos) / FLOOR_TEXTURE_SIZE);
// 		glVertex3f(this->width, 0.0f, this->depth);
// 		
// 		glTexCoord2f(0.0f, _pos / FLOOR_TEXTURE_SIZE);
// 		glVertex3f(this->width, 0.0f, 0.0f);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    void GLCube::drawFrontSide(std::string textureName) {
        this->texturize(textureName);
        this->drawFrontSide();
    }
    
    void GLCube::drawFrontSide() {
        glBegin(GL_QUADS);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, this->depth);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, this->depth);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    void GLCube::drawBackSide(std::string textureName) {
        this->texturize(textureName);
        this->drawBackSide();
    }

    
    void GLCube::drawBackSide() {
        glBegin(GL_QUADS);
        
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, 0.0f);
		
		glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    void GLCube::drawLeftSide(std::string textureName) {
        this->texturize(textureName);
        this->drawLeftSide();
    }
    
    void GLCube::drawLeftSide() {
        glBegin(GL_QUADS);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, this->height, this->depth);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    void GLCube::drawRightSide(std::string textureName) {
        this->texturize(textureName);
        this->drawRightSide();
    }
    
    void GLCube::drawRightSide() {
        glBegin(GL_QUADS);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, 0.0f, 0.0f);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, this->height, this->depth);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }

    GLCube::~GLCube() {

    }

    
}