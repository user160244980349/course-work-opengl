#version 450 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;

smooth out vec4 current_color;

void main() {
   current_color = in_color;
   gl_Position = vec4(in_position);
}
