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
#include "settings.h"
#include "gametable.h"
#include "pane.h"
#include "textureloader.h"
#include <cstdlib>
#include <cmath>

namespace WordGL {

    /**
    * Initalizes the game
    */
    Game::Game(unsigned int newLineInterval):
        dict(WORD_MIN_LENGTH, WORD_MAX_LENGTH),
        //                horiz   vert    vorne            breite tiefe  hoehe
        backGround(Point(-32.0f, -0.2f, -32.0f), Dimension(64.0f, 64.0f, 0.0f)),	//point(x, y, z), Dimension(x, z , y)
        gameTable(Point(0.0f, -0.1f, -9.0f), Dimension(6.0f, 8.0f, 0.0f)),
        scorePanel(Point(0.0f, -0.1f, -10.0f), Dimension(6.0f, 1.0f, 0.0f)),
        letterShelf(Point(0.0f, -0.1f, -1.0f), Dimension(6.0f, 1.0f, 0.0f))
        {
        this->dict.load(DICTIONARY_PATH);
        this->newLineInterval = newLineInterval;
        this->gameTable.addNewLine();
        this->initLetterPoints();
    }
	
	void Game::input(char character){
        // convert upper to lowercase characters
		if(character >= 97 && character <= 122){
            character -= 32;
        }

		if(character >= 65 && character <= 90){
			this->letterShelf.push(character);
		}
        
		//if backspace or entf was pressed
		if(character == 127 || character == 8){
			this->letterShelf.pop();
		}
		
        // if enter is pressed -> Process the word
        if(character == 13){
            this->processInput();
        }
		
	}
	
	void Game::processInput(){
        std::vector<char> characters = this->letterShelf.clear();
        std::string word("");
        for(unsigned int i=0; i<characters.size(); i++){
            word += characters[i];
        }
        
        bool valid = true;
        if(!this->dict.containsWord(word)){
            valid = false;
        }
        if(!this->gameTable.containsCharacters(characters)){
            valid = false;
        }
        
        if(valid){
            this->gameTable.removeWord(characters);
            
            //this->scorePanel.addScore(this->calculateScore(characters));
        } else {
            //this->scorePanel.addScore(-this->calculateScore(characters));
        }
	}

    void Game::update() {
        this->gameTable.getRandomCharacter();
        if(this->timer.getTimeDiff() >= this->newLineInterval){
            this->timer.resetTimer();
            this->gameTable.addNewLine();
        }
        // game over happens when there are more rows than maximum, or score is below 0
        if(this->gameTable.isGameOver() || this->scorePanel.getScore() < 0){
            this->showGameOverScreen();
        }
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
     *         it defaults to the letter entered
     */
    int Game::getLetterIndex(char letter) {
        if(letter >= 65 && letter <= 90){
            return letter - 65;
        } else if(letter >= 97 && letter <= 122){
            return letter - 97;
        } else {
            return letter;
        }
    }

    void Game::showGameOverScreen() {
        exit(0);
    }

    int Game::calculateScore ( std::vector< char > letters ) {
        int score = 0;
        for(unsigned int i=0; i<letters.size(); i++){
            int letterIndex = Game::getLetterIndex(letters[i]);
            int letterScore = this->charPoints[letterIndex];
            // if the word is longer than 3 characters, give a special bonus
            // for every following character
            if(i >= 3){
                letterScore *= (int) pow(2, i-2);
            }
            score += letterScore;
        }
        return score;
    }

    void Game::initLetterPoints() {
        this->charPoints[0] = POINTS_A;
        this->charPoints[1] = POINTS_B;
        this->charPoints[2] = POINTS_C;
        this->charPoints[3] = POINTS_D;
        this->charPoints[4] = POINTS_E;
        this->charPoints[5] = POINTS_F;
        this->charPoints[6] = POINTS_G;
        this->charPoints[7] = POINTS_H;
        this->charPoints[8] = POINTS_I;
        this->charPoints[9] = POINTS_J;
        this->charPoints[10] = POINTS_K;
        this->charPoints[11] = POINTS_L;
        this->charPoints[12] = POINTS_M;
        this->charPoints[13] = POINTS_N;
        this->charPoints[14] = POINTS_O;
        this->charPoints[15] = POINTS_P;
        this->charPoints[16] = POINTS_Q;
        this->charPoints[17] = POINTS_R;
        this->charPoints[18] = POINTS_S;
        this->charPoints[19] = POINTS_T;
        this->charPoints[20] = POINTS_U;
        this->charPoints[21] = POINTS_V;
        this->charPoints[22] = POINTS_W;
        this->charPoints[23] = POINTS_X;
        this->charPoints[24] = POINTS_Y;
        this->charPoints[25] = POINTS_Z;
    }


    Game::~Game(){

    }
    
}