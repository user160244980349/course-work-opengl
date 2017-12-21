#version 450 core

smooth in vec4 vertexColor;
out vec4 finalColor;

void main() {
   finalColor = vertexColor;
}
