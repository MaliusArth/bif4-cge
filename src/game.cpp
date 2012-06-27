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

#include <iostream>

#include "game.h"

namespace WordGL {

    /**
    * Initalizes the game
    */
    Game::Game():
        dict(3, 100){
        this->dict.load("media/dictionary.txt");
    }

    /**
    * Starts the game
    */
    void Game::start(){
        std::cout << this->dict.getRandomWord() << std::endl;
    }


    Game::~Game(){

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
}