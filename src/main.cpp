
#include <iostream>
#include <GL/glew.h> // OpenGL API
#include <GLFW/glfw3.h> // OpenGL toolkit for |window| managment and |input| managment

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


	GLFWwindow* window = glfwCreateWindow( 1024, 768, "Playground", NULL, NULL);
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

	do{
		glClear(GL_COLOR_BUFFER_BIT);

        //something

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
    while(glfwWindowShouldClose(window) == 0);

    glfwTerminate();
    return 0;
}