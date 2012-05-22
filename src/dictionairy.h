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


#ifndef DICTIONAIRY_H
#define DICTIONAIRY_H

#include <vector>
#include <string>

class Dictionairy{

public:
    Dictionairy(int minLength, int maxLength);
    ~Dictionairy();
    void load(const char* path);
    std::string getRandomWord();

private:
    int minLength;
    int maxLength;
    std::vector<std::string> database;
};

#endif // DICTIONAIRY_H
