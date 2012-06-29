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

/**
 * This class keeps track of the score and is responsible for rendering it
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

#include "scorepanel.h"
#include "point.h"
#include "dimension.h"
#include "glcube.h"
#include "lettercube.h"
#include "settings.h"


namespace WordGL {
    
    /**
     * @param startPoint the startPoint where the object should be drawn
     * @param dimension the dimesions of the object
     */
    ScorePanel::ScorePanel(Point startPoint, Dimension dimension): 
		GLCube(startPoint,dimension),
		cubeDimension(Dimension(dimension.getWidth()/WORD_MAX_LENGTH, 
								(dimension.getWidth()/WORD_MAX_LENGTH)-dimension.getHeight(), 
								dimension.getWidth()/WORD_MAX_LENGTH)) {

		//Startpoint at a position, so that all elements are centered on the pane
		GLfloat centeredStartX = this->width - (MAX_SCORE_DISPLAY*this->cubeDimension.getWidth());
		Point currentPoint(this->startX + centeredStartX/2, this->startY, this->startZ);
		currentPoint.setYCoord(this->height);
        
		//For each digit one LetterCube from left to right
		for(int i=0; i < MAX_SCORE_DISPLAY; i++){
            this->cubes.push_back(new LetterCube(currentPoint, this->cubeDimension, '0'));
			currentPoint.setXCoord(currentPoint.getXCoord() + this->cubeDimension.getWidth());
		}

		this->setScore(0);
        this->scoreLowerThanZero = false;
    }


    /**
     * Sets the current score
     * @param score the score
     */
    void ScorePanel::setScore ( int score ) {
        if(score > MAX_SCORE){
			score = MAX_SCORE;
		}
		if(score < 0){
            score = 0;
            this->scoreLowerThanZero = true;
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

    /**
     * Adds points to the current score
     * @param score the new points to add
     */
    void ScorePanel::addScore ( int score ) {
		this->setScore(this->score + score);
    }

    /**
     * Returns the current score
     * @return the current score
     */
    int ScorePanel::getScore() {
        return this->score;
    }

    /**
     * Restarts the score
     */
    void ScorePanel::restart() {
        this->score = 0;
        this->scoreLowerThanZero = false;
    }


    /**
     * Returns true if score was ever lower than zero
     */
    bool ScorePanel::isGameOver() {
        return this->scoreLowerThanZero;
    }

    
    /**
     * Draws the score and its letters
     */
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

    ScorePanel::~ScorePanel() {
        this->cubes.clear();
    }

}


