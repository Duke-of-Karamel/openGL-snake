#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "shaderloader.hpp"

GLuint bindShaders(const char* const vertexshader, const char* const fragmentshader)
{
    GLuint vsID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fsID = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint prgrmID = glCreateProgram();

    // for errors:
    GLint msg_len, ret;
    std::vector<char> msg;


    /////////////////////////////////////////
    ////     compile |VERTEX| shader     ////
    /////////////////////////////////////////
    glShaderSource(vsID, 1, &vertexshader, NULL);
    glCompileShader(vsID);

    //check vertex shader for errors
    glGetShaderiv(vsID, GL_COMPILE_STATUS, &ret);
    if (ret != GL_TRUE){
        glGetShaderiv(vsID, GL_INFO_LOG_LENGTH, &msg_len);
        std::vector<char> msg(msg_len);
        glGetShaderInfoLog(vsID, msg_len, NULL, &msg[0]);
        std::cerr << &msg[0];
    }


    /////////////////////////////////////////
    ////    compile |FRAGMENT| shader    ////
    /////////////////////////////////////////
    glShaderSource(fsID, 1, &fragmentshader, NULL);
    glCompileShader(fsID);

    //check fragment shader for errors
    glGetShaderiv(fsID, GL_COMPILE_STATUS, &ret);
    if (ret != GL_TRUE){
        glGetShaderiv(fsID, GL_INFO_LOG_LENGTH, &msg_len);
        std::vector<char> msg(msg_len);
        glGetShaderInfoLog(fsID, msg_len, NULL, &msg[0]);
        std::cerr << &msg[0];
    }


    /////////////////////////////////////////
    ////   link |PROGRAM| with shaders   ////
    /////////////////////////////////////////
    glAttachShader(prgrmID, vsID);
    glAttachShader(prgrmID, fsID);
    glLinkProgram(prgrmID);

    //check program linking for errors
    glGetProgramiv(prgrmID, GL_LINK_STATUS, &ret);
    if (ret != GL_TRUE){
        glGetProgramiv(prgrmID, GL_INFO_LOG_LENGTH, &msg_len);
        std::vector<char> msg(msg_len);
        glGetProgramInfoLog(prgrmID, msg_len, NULL, &msg[0]);
        std::cerr << &msg[0];
    }


    ////////////////////////////
    ////   FREE resources   ////
    glDetachShader(prgrmID, vsID);
    glDetachShader(prgrmID, fsID);
    glDeleteShader(vsID);
    glDeleteShader(fsID);

    ////////////////////////////
    //// and RETURN program ////
    return prgrmID;
}





std::string readShader(const char* file_path)
{
    std::stringstream str_stream;
    std::ifstream file_stream(file_path, std::ios::in);
    if (!file_stream.is_open()){
        std::cerr << "Shader file: \"" << file_path << "\" could not have been opened\n";
    }

    str_stream << file_stream.rdbuf();

    return str_stream.str();
}