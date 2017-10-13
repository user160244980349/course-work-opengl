#version 450 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;

smooth out vec4 current_color;

uniform shader_data
{
    vec4 color;
    mat4 model;
    mat4 view;
    mat4 projection;
};

void main() {
   current_color = color;
   gl_Position = vec4(in_position);
}
