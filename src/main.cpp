
#include <iostream>
#include <GL/glew.h> // OpenGL API
#include <GLFW/glfw3.h> // OpenGL toolkit for |window| managment and |input| managment
#include <unistd.h>
#include <vector>

#include "shaderloader.hpp"
#include "game.hpp"

#define BUFFER_SIZE 2048

// extern float verticies_in[6];
// extern float colors_in[9];

int main(int argc, char* argv[])
{
	// TODO: Translocate everything to view.cpp
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
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE*sizeof(float)*2, NULL, GL_STREAM_DRAW);
	std::vector<float> verticies_in;

	GLuint index_bufferID;
	glGenBuffers(1, &index_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, BUFFER_SIZE*sizeof(unsigned int)*1, NULL, GL_STREAM_DRAW);
	std::vector<unsigned int> indexing_in;

	GLuint color_bufferID;
	glGenBuffers(1, &color_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, color_bufferID);
	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE*sizeof(float)*3, NULL, GL_STREAM_DRAW);
	std::vector<float> colors_in;

	GLuint prgrmID;
	prgrmID = bindShaders(readShader("src/shaders/vertexshader.glsl").c_str(),readShader("src/shaders/fragmentshader.glsl").c_str()); // FIXME: play with shaders

	Game* game = new Game();
	static Direction direct = UP;

	do{
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(prgrmID);

		// get the verticies, indicies, colors
		game->update(direct,verticies_in,indexing_in,colors_in);
		glNamedBufferSubData(vertex_bufferID,0,verticies_in.size()*sizeof(float),verticies_in.data()); // since 4.5 // consider optimization with smake having to move only last and first part
		glNamedBufferSubData(index_bufferID,0,indexing_in.size()*sizeof(unsigned int),indexing_in.data());
		glNamedBufferSubData(color_bufferID,0,colors_in.size()*sizeof(float),colors_in.data());

        // bind verticies to Shader variable
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_bufferID);
		glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,NULL);

		// bind colors to Shader variable
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, color_bufferID);
		glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,NULL);

		// Draw to screen
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_bufferID);
		glDrawElements(GL_TRIANGLES, indexing_in.size(), GL_UNSIGNED_INT, NULL);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		glfwSwapBuffers(window);
		glfwPollEvents();

		usleep(1000000); // wait a second... :)
	}
    while(glfwWindowShouldClose(window) == 0);

	delete game;
    glfwTerminate();
    return 0;
}