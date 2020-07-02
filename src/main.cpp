
#include <iostream>
#include <GL/glew.h> // OpenGL API
#include <GLFW/glfw3.h> // OpenGL toolkit for |window| managment and |input| managment

#include "shaderloader.hpp"

extern float verticies3D[9];

int main(int argc, char* argv[])
{
    if (!glfwInit()){
        std::cerr << "Error: glfwInit()" <<std::endl;
        return 1;
    }


    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow( 1024, 768, "Snek is hungary as hec", NULL, NULL);
	if(window == NULL){
        std::cerr << "Error: glfwCreateWindow()" <<std::endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK) {
		std::cerr << "Error: glewInit()" <<std::endl;
		glfwTerminate();
		return 1;
	}


    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

	GLuint v_arrayID;
	glGenVertexArrays(1, &v_arrayID); // glCreateVertexArrays(1, &v_arrayID); //????
	glBindVertexArray(v_arrayID);

	GLuint v_bufferID;
	glGenBuffers(1, &v_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, v_bufferID);
	glBufferData(GL_ARRAY_BUFFER, 3*3*sizeof(float), verticies3D, GL_STATIC_DRAW); // FIXME: awfully specific size

	GLuint prgrmID;
	prgrmID = bindShaders(readShader("src/shaders/vertexshader.glsl").c_str(),readShader("src/shaders/fragmentshader.glsl").c_str()); // FIXME: play with shaders

	do{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(prgrmID);

        //something
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, v_bufferID);
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);

		glDrawArrays(GL_TRIANGLES, 0,3);
		glDisableVertexAttribArray(0);
		//something_end

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
    while(glfwWindowShouldClose(window) == 0);

    glfwTerminate();
    return 0;
}