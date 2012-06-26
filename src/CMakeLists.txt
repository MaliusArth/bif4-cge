add_executable(${APPLICATION_NAME} block.cpp globject.cpp dimension.cpp point.cpp gametable.cpp game.cpp dictionary.cpp wrappers.cpp window.cpp main.cpp)

# set up libraries to link
find_package(GLUT)
find_package(OpenGL)

# OpenGL
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    target_link_libraries(${APPLICATION_NAME} ${OPENGL_LIBRARIES})
else(OPENGL_FOUND)
    message("Require OpenGL for video")
endif(OPENGL_FOUND)

# GLUT
if(GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIR})
    target_link_libraries(${APPLICATION_NAME} ${GLUT_LIBRARIES})
else(GLUT_FOUND)
    message("Require GLUT for video")
endif(GLUT_FOUND)

