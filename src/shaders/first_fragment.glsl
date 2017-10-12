#version 450 core

out vec4 output_color;

smooth in vec4 current_color;

void main() {
   output_color = vec4(current_color);
}
