#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

/**
 * binds shaders to program and returns program
 * @return programID
 */
GLuint bindShaders(const char* const vertexshader, const char* const fragmentshader);

/**
 * load shader file to string
 */
std::string readShader(const char* file_path);