/*
    WordGL                                                        *
    Copyright (C) 2012  Bernhard Posselt <bernhard.posselt@gmx.at>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
#include "wrappers.h"

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
    
    // prevent division by 0
    if(height == 0){
        this->height = 1;
    } else {
        this->height = height;
    }
    this->width = width;

    // initial opengl code
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(this->width, this->height);
    glutInitWindowPosition(0, 0);
    this->window = glutCreateWindow(title);
    glutDisplayFunc(&display_wrapper);
    glutReshapeFunc(&resize_wrapper);
    glutKeyboardFunc(&keyPressed_wrapper);
}

/**
 * Initializes the window
 */
void Window::init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    this->resize(this->width, this->height);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    
    glBegin(GL_POLYGON);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    glEnd();
    
    glTranslatef(3.0f,0.0f,0.0f);
    
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    glEnd();
    
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

Window* Window::getInstance(){
    return Window::windowInstance;
}


Window::~Window(){

}






