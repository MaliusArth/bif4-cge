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

#include "scorepanel.h"
#include "point.h"
#include "dimension.h"

namespace WordGL {
    
    ScorePanel::ScorePanel(Point startPoint, Dimension dimension) {
        this->setCoordsDimension(startPoint, dimension);
    }

    ScorePanel::~ScorePanel() {

    }

    void ScorePanel::setScore ( int score ) {
        this->score = score;
    }

    void ScorePanel::addScore ( int score ) {
        this->score += score;
    }

    int ScorePanel::getScore() {
        return this->score;
    }

    
    void ScorePanel::draw() {

    }

}


