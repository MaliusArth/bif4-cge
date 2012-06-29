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
        this->cubeUnit = this->width / this->columns;
        this->longerThanMaximum = false;
        this->cubePadding = CUBE_PADDING;
    }

    /**
     * Draws the table at the coordinates with the given dimension
     */
    void GameTable::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
		glPushMatrix();
        //this->setColor(1.0f, 0.0f, 0.0f);
		this->drawTop(std::string("woodPlanks1"));
		glPopMatrix();
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
            
            Point startPoint(i*this->cubeUnit, 0.1f, 0.0f);
            Dimension dimension(this->cubeUnit-this->cubePadding, this->cubeUnit-this->cubePadding, this->cubeUnit-this->cubePadding);
            GameTableLetterCube* letterCube =
            new GameTableLetterCube(startPoint, dimension, this->getRandomCharacter(), this->cubeUnit);
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
        letterFrequency[22] = 0.0236;
        letterFrequency[23] = 0.0015;
        letterFrequency[24] = 0.0187;
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
    bool GameTable::ifContainsCharactersRemove ( std::vector<char> characters ) {
        std::vector<unsigned int> alreadyFound;

        bool allowed;
        unsigned int matched = 0;
        for(unsigned int i=0; i<characters.size(); i++){
            for(unsigned int j=0; j<this->letterCubes.size(); j++){
                allowed = true;
                // check if we are allowed to check this position
                for(unsigned int foundCounter=0; foundCounter<alreadyFound.size(); foundCounter++){
                    if(j == alreadyFound[foundCounter]){
                        allowed = false;
                    }
                }
                // if we didnt check that letter yet
                if(allowed){
                    if(this->letterCubes[j]->getLetter() == characters[i]){
                        matched++;
                        alreadyFound.push_back(j);
                        break;
                    }
                }

            }
        }

        // if matched remove matched letters from the gametable
        if(matched == characters.size()){
            unsigned int dropId = 0;
            bool drop;
            for(std::vector<GameTableLetterCube*>::iterator it=this->letterCubes.begin(); it!=this->letterCubes.end();){
                drop = false;
                for(unsigned int foundCounter=0; foundCounter<alreadyFound.size(); foundCounter++){
                    if(dropId == alreadyFound[foundCounter]){
                        drop = true;
                    }
                }
                if(drop){
                    it = this->letterCubes.erase(it);
                } else {
                    it++;
                }
                dropId++;
            }
            return true;
        } else {
            return false;
        }
    }


    
    GameTable::~GameTable() {

    }

}
