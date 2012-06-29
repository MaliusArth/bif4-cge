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
#include <cmath>
#include <cstdlib>

namespace WordGL {
    
    ScorePanel::ScorePanel(Point startPoint, Dimension dimension): 
		GLCube(startPoint,dimension),
		cubeDimension(Dimension(dimension.getWidth()/WORD_MAX_LENGTH, 
								dimension.getWidth()/WORD_MAX_LENGTH, 
								dimension.getWidth()/WORD_MAX_LENGTH)) {
			
			//Startpoint at a position, so that all elements are centered on the pane
			GLfloat centeredStartX = this->width - (MAX_SCORE_DISPLAY*this->cubeDimension.getWidth());
			std::cout << centeredStartX << std::endl;
			Point currentPoint(this->startX + centeredStartX/2, this->startY, this->startZ);
			
			//For each digit one LetterCube from left to right
			for(int i=0; i < MAX_SCORE_DISPLAY; i++){
				this->cubes.push_back(new LetterCube(currentPoint, this->cubeDimension, '0'));
				currentPoint.setXCoord(currentPoint.getXCoord() + this->cubeDimension.getWidth());
			}
			
			this->setScore(0);
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
		
		scoreString.insert(0,abs(this->cubes.size() - score_len), '0');
		
		if(!this->cubes.empty()){
			//Go this loop backwards (work the score from right to left)
			for(unsigned int i = this->cubes.size()-1; i >= 0; i--){
				//std::cout << "writing scoreletter ["<< i << "] -> "<< scoreString[i] << std::endl;
				this->cubes[i]->setLetter(scoreString[i]);
				
				//This prevents that the for-loop doesn't decrement a unsigned 0
				if(i == 0){
					break;
				}
			}
		}
    }

    void ScorePanel::addScore ( int score ) {
		this->setScore(this->score + score);
    }

    int ScorePanel::getScore() {
        return this->score;
    }

    
    void ScorePanel::draw() {
		glPushMatrix();
		//Draw the panel itself
        this->move(this->startX, this->startY, this->startZ);
        this->setTexture("wood");
		GLCube::draw();

		//Draw the score-cubes
		for(unsigned int i = 0 ; i < this->cubes.size(); i++){
			this->cubes[i]->draw();
		}
		
        glPopMatrix();
    }

}


