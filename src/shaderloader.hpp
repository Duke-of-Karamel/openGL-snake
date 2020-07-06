#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

/**
 * Binds shaders to program and returns program
 * @return programID
 */
GLuint bindShaders(const char* const vertexshader, const char* const fragmentshader);

/**
 * Loads shader file to string
 * Could actually be any file to string
 */
std::string readShader(const char* file_path);