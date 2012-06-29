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

/**
 * Timer used for the gamelogic
 */

#include <ctime>

#include "timer.h"

namespace WordGL {

    Timer::Timer() {
        this->resetTimer();
    }

    /**
     * Returns the number of miliseconds that have passed since the last reset
     * @return the miliseconds passed since last lookup
     */
    time_t Timer::getTimeDiff() {
        time_t currentTime = time(NULL) * 1000;
        time_t diffTime = currentTime - this->lastTimeSnapshot;
        return diffTime;
    }

    /**
     * Sets the last time snapshot to the current time
     */
    void Timer::resetTimer() {
        this->lastTimeSnapshot = time(NULL) * 1000;
    }

    Timer::~Timer() {
    }

}


