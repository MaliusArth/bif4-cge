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


#include "pane.h"
#include "dimension.h"
#include "point.h"
#include "glcube.h"

namespace WordGL {

    Pane::Pane ( Point startPoint, Dimension dimension ): GLCube(startPoint, dimension) {
    }

    
    void Pane::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(0.0f, 1.0f, 0.0f);
        this->drawBottom();
        glPopMatrix();
    }

    Pane::~Pane() {

    }

}
