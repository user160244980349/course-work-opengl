#version 450 core

out vec4 outputColor;

smooth in vec4 currentColor;

void main() {
   outputColor = vec4(currentColor);
}
