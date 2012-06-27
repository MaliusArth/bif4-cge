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


#pragma once

#include "dictionary.h"
#include "scorepanel.h"
#include "lettershelf.h"
#include "gametable.h"
#include "pane.h"
#include "timer.h"

#include <vector>

namespace WordGL {
    
    class Game {

    public:
        Game(unsigned int newLineInterval);
        ~Game();
        void start();
		void input(char c);
        void update();

    private:
        void processInput();
        int getLetterIndex(char letter);
        void addNewLine();
        void updateInputQueue();
        void updateScore();
        void showGameOverScreen();
        int calculateScore(std::vector<char> letters);
        Timer timer;
        Dictionary dict;
        Pane backGround;
        GameTable gameTable;
        ScorePanel scorePanel;
        LetterShelf letterShelf;
		std::vector<char> inputQueue;
        int charPoints[26];
        unsigned int newLineInterval;
        int score;
        
    };

}