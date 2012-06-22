/*
 *  WordGL                                                        *
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


#include "gametable.h"
#include <boost/concept_check.hpp>

namespace WordGL {

    GameTable::GameTable ( Point startPoint, Dimension dimension ){
        this->startX = startPoint.getXCoord();
        this->startY = startPoint.getYCoord();
        this->startZ = startPoint.getZCoord();
        this->width = dimension.getWidth();
        this->depth = dimension.getDepth();
        this->height = dimension.getHeight();
    }

    /**
     * Draws the table at the coordinates with the given dimension
     */
    void GameTable::draw() {
        glTranslatef(this->startX, this->startY, this->startZ);
        this->drawBottom();
        this->drawFrontSide();
        this->drawBackSide();
        this->drawLeftSide();
        this->drawRightSide();
    }

    void GameTable::drawBottom() {
        this->setColor(1.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, -this->depth);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, 0.0f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -this->depth);
        glVertex3f(this->width, 0.0f, -this->depth);
        glEnd();
    }

    void GameTable::drawFrontSide() {
        this->setColor(0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(this->width, this->height, 0.0f);
        glVertex3f(0.0f, this->height, 0.0f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(this->width, this->height, 0.0f);
        glEnd();
    }

    void GameTable::drawBackSide() {
        this->setColor(0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, -this->depth);
        glVertex3f(this->width, this->height, -this->depth);
        glVertex3f(0.0f, this->height, -this->depth);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, -this->depth);
        glVertex3f(this->width, 0.0f, -this->depth);
        glVertex3f(this->width, this->height, -this->depth);
        glEnd();
    }

    void GameTable::drawLeftSide() {
        this->setColor(1.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -this->depth);
        glVertex3f(0.0f, this->height, -this->depth);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, this->height, -this->depth);
        glVertex3f(0.0f, this->height, 0.0f);
        glEnd();
    }

    void GameTable::drawRightSide() {
        this->setColor(1.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(this->width, 0.0f, -this->depth);
        glVertex3f(this->width, this->height, -this->depth);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(this->width, 0.0f, 0.0f);
        glVertex3f(this->width, this->height, -this->depth);
        glVertex3f(this->width, this->height, 0.0f);
        glEnd();
    }


    
    GameTable::~GameTable() {

    }

}
