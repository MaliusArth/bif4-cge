/**
 *  WordGL
 *  Copyright (C) 2012  Bernhard Posselt <bernhard.posselt@gmx.at>, <viktor.was@technikum-wien.at>
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
 * A pane represents a field. We use it to set the background below the gametable
 */

#include <string>
#include <iostream>	

#include "pane.h"
#include "dimension.h"
#include "point.h"
#include "glcube.h"


namespace WordGL {

    /**
     * @param startPoint the startPoint where the object should be drawn
     * @param dimension the dimesions of the object
     */
    Pane::Pane ( Point startPoint, Dimension dimension ): GLCube(startPoint, dimension) {
    }

    /**
     * Draws the pane
     */
    void Pane::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        this->drawTop(std::string("grass"));
        glPopMatrix();
    }

    /**
     * Overwrites the texturize method for the pane
     */
    void Pane::texturize(std::string textureName){
		TextureLoader* textureLoader = TextureLoader::getInstance();
        GLuint textureId = textureLoader->getTextureId(textureName);

        glEnable(GL_TEXTURE_2D);
 		glBindTexture(GL_TEXTURE_2D, textureId);
 		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	
	void Pane::drawTop(std::string textureName){
        this->texturize(textureName);
//         glBegin(GL_QUADS);
//         
//         glNormal3f(0.0f, 1.0f, 0.0f);
//         
//         glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, this->height, 0.0f);
//         glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, this->height, this->depth);
//         glTexCoord2f(1.0f, 0.0f); glVertex3f(this->width, this->height, this->depth);
//         glTexCoord2f(1.0f, 1.0f); glVertex3f(this->width, this->height, 0.0f);
        
        float _pos = 0.0f;      //The forward position relative to the floor
        const float FLOOR_TEXTURE_SIZE = this->width - _pos; //The size of each "tile"
        
        glBegin(GL_QUADS);
        
        glNormal3f(0.0f, 1.0f, 0.0f);
        
        glTexCoord2f(2000 / FLOOR_TEXTURE_SIZE, _pos / FLOOR_TEXTURE_SIZE);
        glVertex3f(0.0f, this->height, 0.0f);
        
        glTexCoord2f(2000 / FLOOR_TEXTURE_SIZE, (2000 + _pos) / FLOOR_TEXTURE_SIZE);
        glVertex3f(0.0f, this->height, this->depth);
        
        glTexCoord2f(0.0f, (2000 + _pos) / FLOOR_TEXTURE_SIZE);
        glVertex3f(this->width, this->height, this->depth);
        
        glTexCoord2f(0.0f, _pos / FLOOR_TEXTURE_SIZE);
        glVertex3f(this->width, this->height, 0.0f);
        
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }

	Pane::~Pane() {
    }

}
