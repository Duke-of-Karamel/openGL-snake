
#include <iostream>
#include <GL/glew.h> // OpenGL API
#include <GLFW/glfw3.h> // OpenGL toolkit for |window| managment and |input| managment

#include "shaderloader.hpp"

extern float verticies_in[6];
extern float colors_in[9];

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

	GLuint vertex_bufferID;
	glGenBuffers(1, &vertex_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies_in), verticies_in, GL_STATIC_DRAW);

	GLuint color_bufferID;
	glGenBuffers(1, &color_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, color_bufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors_in), colors_in, GL_STATIC_DRAW);

	GLuint prgrmID;
	prgrmID = bindShaders(readShader("src/shaders/vertexshader.glsl").c_str(),readShader("src/shaders/fragmentshader.glsl").c_str()); // FIXME: play with shaders

	do{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(prgrmID);

        // bind verticies to Shader variable
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_bufferID);
		glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,NULL);

		// bind colors to Shader variable
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, color_bufferID);
		glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,NULL);

		glDrawArrays(GL_TRIANGLES, 0,3);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		//something_end

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
    while(glfwWindowShouldClose(window) == 0);

    glfwTerminate();
    return 0;
}