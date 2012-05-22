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


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "dictionairy.h"

/**
 * Initializes the dictionairy
 * @param minLength The minimum length for a word to be read in
 * @param maxLength The maximum length for a word to be read in
 */
Dictionairy::Dictionairy(int minLength, int maxLength){
    this->minLength = minLength;
    this->maxLength = maxLength;
}

/**
 * Reads in the file and builds the database
 * @param path The path to the dictionairy file
 */
void Dictionairy::load(const char* path){
    std::ifstream input(path);
    std::string line;
    if(input){
        while(std::getline(input, line)){
            int length = line.length();
            if(length >= this->minLength && length <= this->maxLength){
                this->database.push_back(line);
            }
        }
    } else {
        std::cerr << "Could not open dictionairy file " << path << std::endl;
    }
}

/**
 * Returns a random word from the dictionairy
 * @return the random word
 */
std::string Dictionairy::getRandomWord(){
    int size = this->database.size();
    srand( time(NULL) );
    int randomNumber = rand() % size;
    return this->database[randomNumber];
}

Dictionairy::~Dictionairy(){

}


