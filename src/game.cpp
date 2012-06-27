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

#include <iostream>

#include "game.h"
#include "gametable.h"
#include "cube.h"
#include "pane.h"
#include "textureloader.h"
#include <cstdlib>

namespace WordGL {

    /**
    * Initalizes the game
    */
    Game::Game(unsigned int newLineInterval):
        dict(3, 100),
        backGround(Point(-32.0f, -0.01f, -32.0f), Dimension(64.0f, 64.0f, 64.0f)),
        gameTable(Point(0.0f, 0.0f, -8.0f), Dimension(6.0f, 8.0f, 0.5f)),
        scorePanel(Point(0.0f, 0.0f, -8.0f), Dimension(6.0f, 8.0f, 0.5f)),
        letterShelf(Point(0.0f, 0.0f, -0.5f), Dimension(6.0f, 8.0f, 0.5f))
        {
        this->dict.load("resources/dict/dictionary.txt");
        this->newLineInterval = newLineInterval;
        this->score = 0;
        this->addNewLine();
    }
	
	void Game::input(char character){
		//If the input character is between aA-zZ
		if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
			this->inputQueue.push_back(character);
		}
        
        //If character is a carriage return -> Process the word
        if(character == 13){
            this->processInput();
        }
		
	}
	
	void Game::processInput(){
        // TODO:
        // 0. clear inputshelf
        // 1. check if input was on board
        // 2. check if string is in dictionary
        // if all correct: calculate score and add points
        // if not, subtract score
        
		for (unsigned int i=0; i < this->inputQueue.size(); i++) {
            std::cout << this->inputQueue[i] << std::endl;
        }
	}

    void Game::update() {
        if(this->timer.getTimeDiff() >= this->newLineInterval){
            this->timer.resetTimer();
            this->addNewLine();
        }
        if(this->gameTable.isGameOver() || score < 0){
            this->showGameOverScreen();
        }
        this->updateInputQueue();
        this->updateScore();
        // draw objects
        this->backGround.draw();
        this->gameTable.draw();
        this->scorePanel.draw();
        this->letterShelf.draw();
    }

    /**
     * Ascii chars can be upper or lower case and are mapped from 65-90 and
     * from 97-122. We only look at lower case letters though. This method returns
     * the index from 0-25 for any given char
     * @param letter The character which is mapped to 0-25
     * @return The index of the character between 0 and 25, if its not a valid character
     *         it defaults to 0
     */
    int Game::getLetterIndex(char letter) {
        if(letter >= 65 && letter <= 90){
            return letter - 65;
        } else if(letter >= 97 && letter <= 122){
            return letter - 97;
        } else {
            return 0;
        }
    }

    void Game::addNewLine() {
        this->gameTable.addNewLine();
    }

    void Game::updateInputQueue() {

    }

    void Game::updateScore() {
        this->scorePanel.setScore(this->score);
    }

    void Game::showGameOverScreen() {
        exit(0);
    }

    int Game::calculateScore ( std::vector< char > letters ) {
        int score = 0;
        for(unsigned int i=0; i<letters.size(); i++){
            int letterIndex = this->getLetterIndex(letters[i]);
            score += this->charPoints[letterIndex];
        }
        return score;
    }


    Game::~Game(){

    }
    
}