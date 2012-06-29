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
 * This class provides texturing and drawing for cube like objects. You dont
 * have to set textures for all side, also you dont have to draw all sides.
 * All methods can be overwritten to fit the needs of the childclass
 */

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif
#include <iostream>
#include <string>

#include "dimension.h"
#include "point.h"
#include "glcube.h"


namespace WordGL {

    /**
     * @param startPoint the startPoint where the object should be drawn
     * @param dimension the dimesions of the object
     */
    GLCube::GLCube(Point startPoint, Dimension dimension) {
        this->setCoordsDimension(startPoint, dimension);
        this->topTexture = false;
        this->bottomTexture = false;
        this->rightTexture = false;
        this->leftTexture = false;
        this->frontTexture = false;
        this->backTexture = false;
    }

    /**
     * Draws all sides of the cube and texturizes the ones where textures have
     * been set
     */
    void GLCube::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
		
        // top
		glPushMatrix();
        this->setColor(1.0f, 1.0f, 1.0f);
        if(this->topTexture){
            this->drawTop(this->topTextureName);
        } else {
            this->drawTop();
        }
        glPopMatrix();
		
		// bottom
		glPushMatrix();
		this->setColor(1.0f, 1.0f, 1.0f);
        if(this->bottomTexture){
            this->drawBottom(this->bottomTextureName);
        } else {
            this->drawBottom();
		}
        glPopMatrix();
		
		// front
		glPushMatrix();
        this->setColor(1.0f, 1.0f, 1.0f);
        if(this->frontTexture){
            this->drawFrontSide(this->frontTextureName);
        } else {
            this->drawFrontSide();
        }
        glPopMatrix();

		//back
		glPushMatrix();
		this->setColor(1.0f, 1.0f, 1.0f);
		if(this->backTexture){
			this->drawBackSide(this->backTextureName);
		} else {
			this->drawBackSide();
		}
		glPopMatrix();
		
		// left
		glPushMatrix();
		this->setColor(1.0f, 1.0f, 1.0f);
		if(this->leftTexture){
			this->drawLeftSide(this->leftTextureName);
		} else {
			this->drawLeftSide();
		}
		glPopMatrix();
		
		// right
		glPushMatrix();
		this->setColor(1.0f, 1.0f, 1.0f);
		if(this->rightTexture){
			this->drawRightSide(this->rightTextureName);
        } else {
			this->drawRightSide();
		}
        glPopMatrix();

		glPopMatrix();
    }
    
	/**
	 * Saves the texture name for the top of the cube
	 */
    void GLCube::setTopTexture ( std::string textureName ) {
		this->topTexture = true;
		this->topTextureName = textureName;
	}
	
	/**
	 * Saves the texture name for the top surface of the cube
	 */
	void GLCube::setBottomTexture ( std::string textureName ) {
		this->bottomTexture = true;
		this->bottomTextureName = textureName;
	}
	
	/**
	 * Saves the texture name for the back surface of the cube
	 */
	void GLCube::setBackTexture ( std::string textureName ) {
		this->backTexture = true;
		this->backTextureName = textureName;
	}
	
	/**
	 * Saves the texture name for the front surface of the cube
	 */
	void GLCube::setFrontTexture ( std::string textureName ) {
		this->frontTexture = true;
		this->frontTextureName = textureName;
	}
	
	/**
	 * Saves the texture name for the right surface of the cube
	 */
	void GLCube::setRightTexture ( std::string textureName ) {
		this->rightTexture = true;
		this->rightTextureName = textureName;
	}
	
	/**
	 * Saves the texture name for the left surface of the cube
	 */
	void GLCube::setLeftTexture ( std::string textureName ) {
		this->leftTexture = true;
		this->leftTextureName = textureName;
	}
	
	/**
	 * Initializes texturing and binds given texture
	 */
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
	
	void GLCube::drawTop(std::string textureName) {
		
		this->texturize(textureName);
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, 1.0f, 0.0f);
		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, this->height, this->depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, this->height, this->depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		
// 		float _pos = 0.0f;		//The forward position relative to the floor
// 		const float FLOOR_TEXTURE_SIZE = this->depth - _pos; //The size of each "tile"
// 		
// 		glBegin(GL_QUADS);
// 		
// 		glNormal3f(0.0f, 1.0f, 0.0f);
// 		
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
	
    void GLCube::drawTop() {
        glBegin(GL_QUADS);
		
		glVertex3f(0.0f, this->height, 0.0f);
		glVertex3f(0.0f, this->height, this->depth);
		glVertex3f(this->width, this->height, this->depth);
		glVertex3f(this->width, this->height, 0.0f);
		
        glEnd();
    }
    
    void GLCube::drawBottom(std::string textureName) {	
		
		this->texturize(textureName);
		
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, -1.0f, 0.0f);
		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); //x... horiz, y... vert; z... depth
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }
    
    void GLCube::drawBottom() {
		glBegin(GL_QUADS);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(this->width, 0.0f, 0.0f);
		glVertex3f(this->width, 0.0f, this->depth);
		glVertex3f(0.0f, 0.0f, this->depth);
		
        glEnd();
    }

    void GLCube::drawFrontSide(std::string textureName) {
		
		this->texturize(textureName);
		
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, 0.0f, 1.0f);		//FIXME check if is set correctly
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, this->depth);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, this->depth);

		glEnd();
		glDisable(GL_TEXTURE_2D);
    }
    
    void GLCube::drawFrontSide() {
        glBegin(GL_QUADS);
		
		glVertex3f(0.0f, 0.0f, this->depth);
		glVertex3f(this->width, 0.0f, this->depth);
		glVertex3f(this->width, this->height, this->depth);
		glVertex3f(0.0f, this->height, this->depth);
		
        glEnd();
    }

    void GLCube::drawBackSide(std::string textureName) {
		
		this->texturize(textureName);
		
		glBegin(GL_QUADS);
		
		glNormal3f(0.0f, 0.0f, -1.0f);		//FIXME check if is set correctly
        
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, 0.0f);
		
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

    
    void GLCube::drawBackSide() {
        glBegin(GL_QUADS);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, this->height, 0.0f);
		glVertex3f(this->width, this->height, 0.0f);
		glVertex3f(this->width, 0.0f, 0.0f);
		
		glEnd();
    }

    void GLCube::drawLeftSide(std::string textureName) {
		
		this->texturize(textureName);
		
		glBegin(GL_QUADS);
		
		glNormal3f(-1.0f, 0.0f, 0.0f);
		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, this->depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, this->height, this->depth);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
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
		
		this->texturize(textureName);
		
		glBegin(GL_QUADS);
		
		glNormal3f(1.0f, 0.0f, 0.0f);
		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(this->width, this->height, this->depth);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(this->width, 0.0f, this->depth);
		
        glEnd();
		glDisable(GL_TEXTURE_2D);
    }
    
    void GLCube::drawRightSide() {
        glBegin(GL_QUADS);
		
		glVertex3f(this->width, 0.0f, 0.0f);
		glVertex3f(this->width, this->height, 0.0f);
		glVertex3f(this->width, this->height, this->depth);
		glVertex3f(this->width, 0.0f, this->depth);
		
        glEnd();
    }

	void GLCube::setTexture(std::string textureName){
		this->setTopTexture(textureName);
		this->setFrontTexture(textureName);
		this->setBackTexture(textureName);
		this->setBottomTexture(textureName);
		this->setLeftTexture(textureName);
		this->setRightTexture(textureName);
	}
	
    GLCube::~GLCube() {

    }

    
}