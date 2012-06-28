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

#ifdef __APPLE__
    #include <OpenGL/gl.h>
#else
    #include <GL/gl.h>
#endif

#include "gametablelettercube.h"
#include "lettercube.h"
#include "point.h"
#include "dimension.h"

namespace WordGL {

    GameTableLetterCube::GameTableLetterCube(Point startPoint, Dimension dimension, char letter, GLfloat cubeUnit):
        LetterCube(startPoint, dimension, letter){
        this->column = 0;
        this->row = 0;
        this->cubeUnit = cubeUnit;
    }

    unsigned int GameTableLetterCube::getColumn() {
        return this->column;
    }

    unsigned int GameTableLetterCube::getRow() {
        return this->row;
    }
    
    void GameTableLetterCube::incrementRow() {
        this->row += 1;
        this->startX += this->cubeUnit;
    }

    
    GameTableLetterCube::~GameTableLetterCube() {

    }
    
}


