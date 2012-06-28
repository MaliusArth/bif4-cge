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
	
    LetterShelf::LetterShelf(Point startPoint, Dimension dimension):GLCube(startPoint,dimension),currentPoint(0.0f,0.0f,0.0f){
        this->setCoordsDimension(startPoint, dimension);
		this->max_letters = WORD_MAX_LENGTH;
    }

	LetterShelf::~LetterShelf() {

    }
	
	void LetterShelf::push(char character){
		//If the lettershelf is full, don't do anything
		if(this->cubes.size() + 1 >= this->max_letters) {
			return;
		}
		
		//LetterCube cube erstellen
		
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
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(1.0f, 1.0f, 1.0f);
        this->drawBottom();
        glPopMatrix();
    }
}