#version 330 core

layout(location = 0) in vec2 vertex_coordinates;
layout(location = 1) in vec3 vertex_color;

out vec3 fragment_color;

void main(){
    gl_Position.xy = vertex_coordinates;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;

    fragment_color = vertex_color;
}