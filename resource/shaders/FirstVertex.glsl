#version 460 core

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec4 inColor;

smooth out vec4 currentColor;

uniform camera {
    mat4 projection;
    mat4 viewPoint;
};

uniform object {
    mat4 model;
};

void main() {
   currentColor = inColor;
   gl_Position = projection * viewPoint * model * vec4(inPosition);
}
