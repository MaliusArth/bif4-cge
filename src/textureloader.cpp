/**
 *  WordGL
 *  Copyright (C) 2012  Viktor Was <viktor.was@technikum-wien.at>
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

#include <vector>
#include <string>
#include <utility>

#include "textureloader.h"
#include "imageloader.h"


namespace WordGL {

    TextureLoader::TextureLoader(){
    }

    void TextureLoader::loadTexturesFromDirectory ( const char* path ) {
        // TODO: list all textures in directory and call loadMipmappedTexture
        // for each one of them
    }


    /**
     * Loads multiple textures at once and turns the image into a mipmapped texture,
     * then the textureid is stored in a vector
     * @param *image
     */
    void TextureLoader::loadMipmappedTexture(Image *image) {
        GLuint textureId;
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        gluBuild2DMipmaps(GL_TEXTURE_2D,
                GL_RGB,
                image->width, image->height,
                GL_RGB,
                GL_UNSIGNED_BYTE,
                image->pixels);
        
        // push filename and id into vector
        std::pair<std::string, GLuint> hashPair;
        // TODO: get filename of *image
        // std::string filename = image->getFileName();
        std::string filename("");
        hashPair = make_pair(filename, textureId);
        
        this->textureIds.insert(hashPair);
        delete image;
    }



    TextureLoader::~TextureLoader(){

    }

}
