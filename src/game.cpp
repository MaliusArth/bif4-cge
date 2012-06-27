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


namespace WordGL {

    /**
    * Initalizes the game
    */
    Game::Game():
        dict(3, 100){
        this->dict.load("resources/dict/dictionary.txt");
    }
	
	void Game::input(char c){
		//If the input character is between aA-zZ
		if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
			this->inputQueue.push_back(c);
		}
        
        //If character is a carriage return -> Process the word
        if(c == 13){
            this->processInput();
        }
		
	}
	
	void Game::processInput(){
		for (unsigned int i=0; i < this->inputQueue.size(); i++) {
            std::cout << this->inputQueue[i] << std::endl;
        }
	}

    void Game::drawAll() {
        // draw the general background
        Point bgPosition(-32.0f, -0.01f, -32.0f);
        Dimension bgDimension(64.0f, 64.0f, 64.0f);
        Pane bg(bgPosition, bgDimension);
        bg.draw();
        
        // position the gameTable
        Point gameTablePosition(0.0f, 0.0f, -8.0f);
        Dimension gameTableDimension(6.0f, 8.0f, 0.5f);
        GameTable gameTable(gameTablePosition, gameTableDimension);
        // NOTE: everything that is drawn after the gameTable is positioned
        // relatively to the gametables origin -> 0, 0, 0 would be in the upper
        // left corner
        gameTable.draw();

        // print a cube
        Point cubePosition(0.0f, 0.0f, 0.0f);
        Dimension cubeDimension(0.5f, 0.5f, 0.5f);
        Cube cube(cubePosition, cubeDimension);
        cube.draw();
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


    Game::~Game(){

    }
    
}