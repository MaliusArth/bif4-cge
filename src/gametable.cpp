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


#include "gametable.h"
#include "textureloader.h"
#include "settings.h"
#include "glcube.h"
#include "point.h"
#include "dimension.h"
#include "gametablelettercube.h"

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>

namespace WordGL {

    GameTable::GameTable ( Point startPoint, Dimension dimension ): GLCube(startPoint, dimension){
        this->columns = GAMETABLE_COLUMNS_NUM;
        this->rows = GAMETABLE_ROWS_NUM;
        this->rowUnit = this->width / this->rows;
        this->longerThanMaximum = false;
    }

    /**
     * Draws the table at the coordinates with the given dimension
     */
    void GameTable::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        //this->setColor(1.0f, 0.0f, 0.0f);
		this->drawBottom(std::string("checkerboard"));
        for(unsigned int i=0; i<this->letterCubes.size(); i++){
            this->letterCubes[i]->draw();
        }
        glPopMatrix();
    }

    void GameTable::addNewLine() {
        // move all lettercubes one level down
        for(unsigned int i=0; i<this->letterCubes.size(); i++){
            this->letterCubes[i]->incrementRow();
        }

        // create new row
        for(unsigned int i=0; i<this->columns; i++){
            Point startPoint(i*this->rowUnit, 0.0f, 0.0f);
            Dimension dimension(this->rowUnit, this->rowUnit, 0.5f);
            GameTableLetterCube* letterCube =
                new GameTableLetterCube(startPoint, dimension, this->getRandomCharacter(), this->rowUnit);
            this->letterCubes.push_back(letterCube);
        }
        

        // check if the oldest element exceeds the maximum length
        if(this->letterCubes[0]->getRow() >= this->rows){
            this->longerThanMaximum = true;
        }
    }

    /**
     * Get a random character based on the probability of the letter
     */
    char GameTable::getRandomCharacter() {
        // default random character
        char randomChar = 'a';
        // store letter frequency
        double letterFrequency[26];
        letterFrequency[0] = 0.0816;
        letterFrequency[1] = 0.0149;
        letterFrequency[2] = 0.0278;
        letterFrequency[3] = 0.0425;
        letterFrequency[4] = 0.1270;
        letterFrequency[5] = 0.0228;
        letterFrequency[6] = 0.0202;
        letterFrequency[7] = 0.0609;
        letterFrequency[8] = 0.0697;
        letterFrequency[9] = 0.0015;
        letterFrequency[10] = 0.0074;
        letterFrequency[11] = 0.0402;
        letterFrequency[12] = 0.0251;
        letterFrequency[13] = 0.0674;
        letterFrequency[14] = 0.0750;
        letterFrequency[15] = 0.0192;
        letterFrequency[16] = 0.0009;
        letterFrequency[17] = 0.0598;
        letterFrequency[18] = 0.0633;
        letterFrequency[19] = 0.0905;
        letterFrequency[20] = 0.0275;
        letterFrequency[21] = 0.0103;
        letterFrequency[22] = 0.0246;
        letterFrequency[23] = 0.0015;
        letterFrequency[24] = 0.0197;
        letterFrequency[25] = 0.0007;
        
        int randomNumber = rand() % 10000;

        double lastProbability = 0.0;
        for(int i=0; i<26; i++){
            lastProbability += letterFrequency[i];
            if(randomNumber <= floor(lastProbability*10000)){
                randomChar = 97 + i;
                break;
            }
        }
        return randomChar;
    }

    bool GameTable::isGameOver() {
        return this->longerThanMaximum;
    }       

    /**
     * Check if the gametable contains the letters we entered
     */
    bool GameTable::containsCharacters ( std::vector<char> characters ) {
        // check each lettercube we got if the current character matches it
        for(unsigned int i=0; i<this->letterCubes.size(); i++){
            for(unsigned int j=characters.size()-1; j>=0; j--){
                if(characters[j] == this->letterCubes[i]->getLetter()){
                    characters.erase(characters.begin()+j);
                }
            }
        }
        
        if(characters.size() == 0){
            return true;
        } else {
            return false;
        }
        
    }

    /**
     * Removes the word from the gametable
     */
    void GameTable::removeWord ( std::vector< char > characters ) {
        // the oldest letter is in the beginning
        for(unsigned int i=0; i<letterCubes.size(); i++){
            for(unsigned int j=characters.size()-1; j>=0; j--){
                if(characters[j] == this->letterCubes[i]->getLetter()){
                    this->letterCubes.erase(this->letterCubes.begin()+i);
                }
            }
        }
    }

    
    GameTable::~GameTable() {

    }

}
