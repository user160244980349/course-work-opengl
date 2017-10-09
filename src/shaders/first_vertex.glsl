#version 450 core

layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec3 inColor;

smooth out vec3 currentColor;

void main() {
   currentColor = inColor;   //Передаем информацию о цвете в пиксельный шейдер
   gl_Position = vec4(inPosition, 0.0, 1.0);   //Задаем положение вершины
}
