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
 * This class is responsible for setting up opengl and initializing the game,
 * passing input to it and tell it to update
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
#include <cstdlib>
#include <iostream>
#include <cmath>

#include <unistd.h>

#include "window.h"
#include "game.h"
#include "wrappers.h"
#include "settings.h"

namespace WordGL {
    
    // needed singleton for wrappers
    Window* Window::windowInstance = NULL;
    
    /**
    * Creates the window
    * @param title The window title
    * @param width The width of the window
    * @param height The height of the window
    */
    Window::Window (int* argc, char** argv, const char* title, int width, int height):
		game(LINE_UPDATE_INTERVAL){
        Window::windowInstance = this;
        this->title = title;
        // prevent division by 0
        if(height == 0){
            this->height = 1;
        } else {
            this->height = height;
        }
        this->width = width;
		this->eyeX = 3.0f;
		this->eyeY = 13.0f;
		this->eyeZ = 7.0f;
		this->centerX = 3.0f;
		this->centerY = 0.0f;
		this->centerZ = -6.0f;
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
        
        // initialize rendering	
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);

        // get window refresh rate and interval
        this->windowRefreshRate = glutGameModeGet(GLUT_GAME_MODE_REFRESH_RATE);
        if(this->windowRefreshRate <= 0){
            this->windowRefreshRate = 60;
        }
        this->windowRefreshInterval = (int) floor(1000/this->windowRefreshRate);
        std::cout << "Rendering with " << this->windowRefreshRate << " hz" << std::endl;
        
        glutDisplayFunc(&display_wrapper);
        glutReshapeFunc(&resize_wrapper);
        glutKeyboardFunc(&keyPressed_wrapper);
		//Arrow-Key functions
		glutSpecialFunc(&keySpecial_wrapper);
        glutTimerFunc(this->windowRefreshInterval, &timer_wrapper, 1);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0);
        glDepthFunc(GL_LESS);
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
        // clear screen and position camera
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		gluLookAt( this->eyeX, this->eyeY, this->eyeZ,
                   this->centerX, this->centerY, this->centerZ,
                   0, 0.0f, -1.0f);
		glTranslatef(this->centerX, this->centerY, this->centerZ);
		glRotatef(this->angle, 0, 1.0, 0);
		glTranslatef(this->centerX*(-1), this->centerY*(-1), this->centerZ*(-1));
		
        // draw game objects
        this->game.update();
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
        this->game.input(key);
    }

    /**
     * Checks for arrow keys
     */
	void Window::specialKeyPressed(int key, int x, int y){
		switch(key){
			case GLUT_KEY_UP:
                if(this->eyeY > 4.0){
					this->eyeY -= 0.5;
				}
				break;
			
			case GLUT_KEY_DOWN:
                if(this->eyeY < 20.0){
					this->eyeY += 0.5;
				}
				break;
                
			case GLUT_KEY_RIGHT:
                this->angle = fmod(this->angle + 5.0, 360.0);
				break;
                
			case GLUT_KEY_LEFT:
                this->angle = fmod(this->angle - 5.0, 360.0);
				break;
                
			default:
                return;
		}
	}

	/**
     * Redisplays the window and sets the timer to do it again
     * @param value integer which can be passed
     */
    void Window::redisplayTimer(int value) { 
        glutPostRedisplay();
        glutTimerFunc(this->windowRefreshInterval, &timer_wrapper, value);
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
