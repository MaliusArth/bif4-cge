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

#include <vector>

#include "point.h"
#include "dimension.h"
#include "glcube.h"
#include "lettercube.h"

namespace WordGL{
    
    class ScorePanel: public GLCube {

    public:
        ScorePanel(Point startPoint, Dimension dimension);
        virtual ~ScorePanel();
        void draw();
        void setScore(int score);
        void addScore(int score);
        int getScore();
        
    private:
        int score;
		Dimension cubeDimension;
		std::vector<LetterCube*> cubes;
    };
    
}



