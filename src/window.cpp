/*
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

#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <stdlib.h>
#include <unistd.h>

#include "window.h"
#include "game.h"
#include "wrappers.h"
#include "gametable.h"
#include "cube.h"

namespace WordGL {
    
    // initialize static member variable with null
    Window* Window::windowInstance = NULL;

    /**
    * Creates the window
    * @param title The window title
    * @param width The width of the window
    * @param height The height of the window
    */
    Window::Window (int* argc, char** argv, const char* title, int width, int height){
        Window::windowInstance = this;
        this->title = title;
        // prevent division by 0
        if(height == 0){
            this->height = 1;
        } else {
            this->height = height;
        }
        this->width = width;
        glutInit(argc, argv);
    }

    /**
    * Initializes the window
    */
    void Window::init(){
        // initial opengl code
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
        glutInitWindowSize(this->width, this->height);
        glutInitWindowPosition(0, 0);
        this->window = glutCreateWindow(this->title);
        glutDisplayFunc(&display_wrapper);
        glutReshapeFunc(&resize_wrapper);
        glutKeyboardFunc(&keyPressed_wrapper);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);
        this->resize(this->width, this->height);
        glutFullScreen();
        glutMainLoop();
    }



    /**
    * Resizes the window to a certain height
    * @param width The new width
    * @param height The new height
    */
    void Window::resize( int width, int height ){
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
    }

    /**
    * Displays the window
    */
    void Window::display(){
        // game logic in here?
        Game game;
        game.start();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt( 3.0f, 10.0f, 0.0f,
                   3.0f, 0.0f, -3.5f,
                   0, 1.0f, -1.0f);
        
        // position the gameTable
        Point gameTablePosition(0.0f, 0.0f, -8.0f);
        Dimension gameTableDimension(6.0f, 8.0f, 0.5f);
        GameTable gameTable(gameTablePosition, gameTableDimension);
        gameTable.draw();

        // print a cube
        Point cubePosition(0.0f, 0.0f, 0.0f);
        Dimension cubeDimension(0.5f, 0.5f, 0.5f);
        Cube cube(cubePosition, cubeDimension);
        cube.draw();
        
        glutSwapBuffers();
    }

    /**
    * Handles input events from the keyboard
    * @param key The key which was pressed
    * @param x The x position where the key was pressed
    * @param y The y position where the key was pressed
    */
    void Window::keyPressed(unsigned char key, int x, int y){
        usleep(100);

        if(key == 27){
            glutDestroyWindow(this->window);
            exit(0);
        }
    }

    /**
    * Returns a static instance of the window. Used for wrapper functions for OpenGL
    * @return The window instance
    */
    Window* Window::getInstance(){
        return Window::windowInstance;
    }


    Window::~Window(){

    }

}
