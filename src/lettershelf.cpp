/**
 *  WordGL
 *  Copyright (C) 2012  Patrick Stapfer <p.stapfer@technikum-wien.at>
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


#include "lettershelf.h"
#include "dimension.h"
#include "point.h"
#include "settings.h"
#include "lettercube.h"

#include <iostream>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {
	
    LetterShelf::LetterShelf(Point startPoint, Dimension dimension):
								GLCube(startPoint,dimension),
								cubeDimension(Dimension(dimension.getWidth()/WORD_MAX_LENGTH, dimension.getWidth()/WORD_MAX_LENGTH, 0.5f)),
								currentPoint(startPoint)
								{
		this->currentPoint.setYCoord(0.02f);
    }

	LetterShelf::~LetterShelf() {

    }
	  
	void LetterShelf::push(char character){
		//If the lettershelf is full, don't do anything
		if(this->cubes.size() >= WORD_MAX_LENGTH) {
			return;
		}
		
		//The first cube gets on the initial-position of the lettershelf
		if(this->cubes.empty()){
			this->currentPoint.setXCoord(startX);
		}
		else{
			GLfloat currentX = this->currentPoint.getXCoord();
			std::cout << "X: " << currentX << "CubeWidth: " << this->cubeDimension.getWidth() << std::endl;
			this->currentPoint.setXCoord(currentX + cubeDimension.getWidth());
		}
		
		//LetterCube cube erstellen
		this->cubes.push_back(new LetterCube(this->currentPoint, this->cubeDimension, character));
	}
	
	void LetterShelf::pop(){	
		if(this->cubes.empty()){
			this->currentPoint.setXCoord(startX);
		}
		else{
			GLfloat currentX = this->currentPoint.getXCoord();
			this->currentPoint.setXCoord(currentX - cubeDimension.getWidth());
			this->cubes.pop_back();
		}
		
	}	
	
	std::vector<char> LetterShelf::clear(){
		std::vector<char> ret;
		for(unsigned int i = 0; i < this->cubes.size(); i++){
			ret.push_back(this->cubes[i]->getLetter());
		}
		
		//Clear the cube-vector
		this->cubes.clear();
		
		//Reset position-marker
		this->currentPoint.setXCoord(this->startX);
		
		return ret;
	}

    void LetterShelf::draw() {
		glPushMatrix();
		
		glRotatef(-10, 1,0,0);
		
		//Draw the panel itself
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(1.0f, 1.0f, 1.0f);
        this->drawBottom();

		//Draw the input-cubes
		for(unsigned int i = 0 ; i < this->cubes.size(); i++){
			this->cubes[i]->draw();
		}
		
        glPopMatrix();
    }
}