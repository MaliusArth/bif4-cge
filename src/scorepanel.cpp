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

#include "scorepanel.h"
#include "point.h"
#include "dimension.h"
#include "glcube.h"
#include "lettercube.h"
#include "settings.h"
#include <vector>
#include <iostream>
#include <sstream>

namespace WordGL {
    
    ScorePanel::ScorePanel(Point startPoint, Dimension dimension): 
		GLCube(startPoint,dimension),
		cubeDimension(Dimension(dimension.getWidth()/WORD_MAX_LENGTH, dimension.getWidth()/WORD_MAX_LENGTH, 0.5f)) {
			this->setScore(0);
			
			Point currentPoint(this->startX, this->startY, this->startZ);
			
			//For each digit one LetterCube from left to right
			for(int i=0; i < MAX_SCORE_DISPLAY; i++){
				this->cubes.push_back(new LetterCube(currentPoint, this->cubeDimension, '0'));
				currentPoint.setXCoord(currentPoint.getXCoord() + this->cubeDimension.getWidth());
			}
    }

    ScorePanel::~ScorePanel() {

    }

    void ScorePanel::setScore ( int score ) {
        if(score > MAX_SCORE){
			score = MAX_SCORE;
		}
		
		this->score = score;
		
		//Update the letter represented by the score-cubes
		std::stringstream ss;
		ss << score;
		
		std::string scoreString = ss.str();
		size_t score_len = scoreString.size();
		
		//Go this loop backwards (work the score from right to left)
        /* SEGFAULTS
		for(unsigned int i = this->cubes.size(); i > 0; i--){
			if(score_len >= i){
				this->cubes[i]->setLetter(scoreString[i]);
			}
			else{
				this->cubes[i]->setLetter('0');
			}
		}*/
    }

    void ScorePanel::addScore ( int score ) {
		this->addScore(this->score + score);
    }

    int ScorePanel::getScore() {
        return this->score;
    }

    
    void ScorePanel::draw() {
		glPushMatrix();
		
		//glRotatef(-20, 1,0,0);
		
		//Draw the panel itself
        this->move(this->startX, this->startY, this->startZ);
        this->setColor(1.0f, 1.0f, 1.0f);
        this->drawBottom();

		//Draw the score-cubes
		for(unsigned int i = 0 ; i < this->cubes.size(); i++){
			this->cubes[i]->draw();
		}
		
        glPopMatrix();
    }

}


