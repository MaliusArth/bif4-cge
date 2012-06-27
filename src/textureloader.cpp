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
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <utility>

#include "textureloader.h"
#include "imageloader.h"

using namespace std;

namespace WordGL {

    TextureLoader::TextureLoader(){
    }

    void TextureLoader::loadTexturesFromDirectory ( string path ) {
        // TODO: list all textures in directory and call loadMipmappedTexture
        // for each one of them
        DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(path.c_str())) == NULL) {
	    cout << "Error(" << errno << ") opening " << path << endl;
	    //return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
	    Image* image = loadBMP(path + string(dirp->d_name));
	    loadMipmappedTexture(image, path + string(dirp->d_name));
	    delete image;
	    cout << path << string(dirp->d_name) << endl;
	}
	closedir(dp);
	//return 0;
    }


    /**
     * Loads multiple textures at once and turns the image into a mipmapped texture,
     * then the textureid is stored in a vector
     * @param *image
     */
    void TextureLoader::loadMipmappedTexture(Image *image, string filename) {
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
        typedef std::pair<std::string, GLuint> stringIdPair;
        this->textureIds.insert(stringIdPair(filename, textureId));
        //delete image;
    }

    GLuint TextureLoader::getTextureId ( std::string key ) {
        return this->textureIds.find(key)->second;
    }


    TextureLoader::~TextureLoader(){

    }

}
