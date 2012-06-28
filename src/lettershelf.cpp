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

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

namespace WordGL {
	
    LetterShelf::LetterShelf(Point startPoint, Dimension dimension):
								GLCube(startPoint,dimension),
								cubeDimension(Dimension(dimension.getWidth()/WORD_MAX_LENGTH, dimension.getDepth(), 0.5f)),
								currentPoint(startPoint)
								{
		this->max_letters = WORD_MAX_LENGTH;
		this->currentPoint.setYCoord(+0.05f);
    }

	LetterShelf::~LetterShelf() {

    }
	
	void LetterShelf::push(char character){
		unsigned int cubeNumber = this->cubes.size();
		//If the lettershelf is full, don't do anything
		if(cubeNumber + 1 >= this->max_letters) {
			return;
		}
		
		if(cubeNumber > 0){
			int currentX = this->currentPoint.getXCoord();
			this->currentPoint.setXCoord(currentX + cubeDimension.getWidth());
		}
		
		
		//LetterCube cube erstellen
		this->cubes.push_back(LetterCube(this->currentPoint, this->cubeDimension, character));
	}
	
	void LetterShelf::pop(){
		
	}	
	
	std::vector<char> LetterShelf::clear(){
		std::vector<char> ret;
		for(unsigned int i = 0; i < this->cubes.size(); i++){
			ret.push_back(this->cubes[i].getLetter());
		}
		
		return ret;
	}

    void LetterShelf::draw() {
		glPushMatrix();
		
		//Draw the panel itself
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(1.0f, 1.0f, 1.0f);
        this->drawBottom();

		//Draw the input-cubes
		for(unsigned int i = 0 ; i < this->cubes.size(); i++){
			this->cubes[i].draw();
		}
		
        glPopMatrix();
    }
}