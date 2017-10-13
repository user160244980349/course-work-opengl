#version 450 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;

smooth out vec4 current_color;

uniform shader_data
{
    mat4 projection;
    mat4 view;
    mat4 model;
};

void main() {
   current_color = in_color;
   gl_Position = projection * view * model * vec4(in_position);
}
