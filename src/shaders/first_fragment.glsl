#version 450 core

out vec4 outputColor;

smooth in vec3 currentColor;

void main() {
   outputColor = vec4(currentColor, 1.0);   //Задаем цвет пикселя
}
