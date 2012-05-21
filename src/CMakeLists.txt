add_executable(bif4-cge wrappers.cpp window.cpp main.cpp)

# set up libraries to link
find_package(GLUT)
find_package(OpenGL)

if(GLUT_FOUND AND OPENGL_FOUND)
    include_directories(${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${APPLICATION_NAME} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES})
else(GLUT_FOUND AND OPENGL_FOUND)
    message("Require GLUT and OpenGL to build")
endif(GLUT_FOUND AND OPENGL_FOUND)