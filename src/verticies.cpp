#include <GL/glew.h>
#include <GLFW/glfw3.h>


// trapezoid
float verticies_in[8] = {
    -0.8, -0.8,
    -0.6, +0.8,
    +0.8, +0.8,
    +0.6, -0.8
};

unsigned int indexing_in[6] = {
    0,1,3,
    1,3,2
};

float colors_in[12] = {
    0.7f, 0.5f, 0.0f,
    0.7f, 0.3f, 0.0f,
    0.7f, 0.3f, 0.0f,
    0.9f, 0.3f, 0.0f,
};