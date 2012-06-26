/*
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



#include "glcube.h"

namespace WordGL {

    GLCube::GLCube() {

    }
    
    void GLCube::drawBottom() {
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

    void GLCube::drawTop() {

    }

    void GLCube::drawFrontSide() {
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

    void GLCube::drawBackSide() {
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

    void GLCube::drawLeftSide() {
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

    void GLCube::drawRightSide() {
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

    GLCube::~GLCube() {

    }

    
}