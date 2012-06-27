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

namespace WordGL {
    
    Cube::Cube ( Point startPoint, Dimension dimension ) {
        this->setCoordsDimension(startPoint, dimension);
    }

    void Cube::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(0.3f, 1.0f, 0.1f);
        this->drawTop();
        this->drawBottom();
        this->setColor(0.5f, 1.0f, 0.1f);
        this->drawFrontSide();
        this->drawBackSide();
        this->setColor(0.0f, 1.0f, 0.7f);
        this->drawLeftSide();
        this->drawRightSide();
        glPopMatrix();
    }

    
    Cube::~Cube() {

    }
    
}



