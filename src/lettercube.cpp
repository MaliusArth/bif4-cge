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

/**
 * Represents a cube with a header texture
 */

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif
#include <string>

#include "glcube.h"
#include "lettercube.h"

namespace WordGL {
    
    /**
     * @param startPoint the startPoint where the object should be drawn
     * @param dimension the dimesions of the object
     * @param letter the texture id for the top
     */
    LetterCube::LetterCube (Point startPoint, Dimension dimension, char letter): GLCube(startPoint,dimension) {	
		this->setLetter(letter);
    }

    /**
     * Returns the letter from the header texture
     * @return the letter which was set
     */
	char LetterCube::getLetter(){
		return this->letter;
	}

	/**
     * sets a letter for the header texture
     */
	void LetterCube::setLetter(char letter){
        this->letter = letter;
        std::string textureName("");
        textureName += this->letter;
		this->setTopTexture(textureName);
	}

    LetterCube::~LetterCube() {
    }

}
