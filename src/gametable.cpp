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

#include <vector>

namespace WordGL {

    GameTable::GameTable ( Point startPoint, Dimension dimension ): GLCube(startPoint, dimension){
        this->columns = GAMETABLE_COLUMNS_NUM;
        this->rows = GAMETABLE_ROWS_NUM;
        this->longerThanMaximum = false;
    }

    /**
     * Draws the table at the coordinates with the given dimension
     */
    void GameTable::draw() {
        glPushMatrix();
        this->move(this->startX, this->startY, this->startZ);
        this->drawBottom("checkerboard");
        glPopMatrix();
    }

    void GameTable::addNewLine() {
        // check if we move longer than maximum
        for(unsigned int i=0; i<this->columns; i++){
            //Point ;
            //GameTableLetterCube* letterCube = new LetterCube();
            //this->letterCubes.push_back(letterCube);
        }
        // TODO: move all lettercubes one level down
    }

    /**
     * Get a random character based on the probability of the letter
     */
    char GameTable::getRandomCharacter() {
        return 'a';
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
