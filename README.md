# Build Instructions

To build it, you require

* [CMake](http://www.cmake.org/cmake/resources/software.html)
* [Glut/FreeGlut](http://freeglut.sourceforge.net/index.php#download)
* OpenGL

After installation, run

    ./build.sh

to build it. If you also want to start it, run

    ./build.sh -r

The game builds on Mac OS X and Linux

# Game description
This game is a mix of Bubble Bobble and Scrabble. Every 5 seconds a new line of
letters appears at the top of the creen. The existing ones move down by one row.

When the row reaches more than 11 rows, you lose. You also lose when you go below 0
points.

To remove the characters, type in words that are at between 3 and 8 characters.
If this word is in the dictionary you get points for it and the letters are removed.
When the word is longer than 3 characters you get a bonus for every following character.
The fourth character gets 2 times its points, the fifth gets 4 times its points,
the sixth gets 8 times its points and so on.

# Controls
* ESC - Quit
* BACKSPACE - Remove last typed letter
* ENTER - Confirm the word you typed in

Words can only contain ASCII characters

# Authors
* Bernhard Posselt: 	Window & OpenGL inits, basic classes, game logic, gametable
* Patrick Stapfer:	input, score, camera, various fixes & changes
* Viktor Was:		BMP loading, graphics, drawing, texturing, lighting
