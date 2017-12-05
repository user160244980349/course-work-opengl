#version 450 core

in vec3 vertexPosition;
smooth out vec4 vertexColor;

uniform camera {
    mat4 projection;
    mat4 viewPoint;
};

uniform object {
    mat4 model;
};

void main() {
   vertexColor = vec4(vertexPosition, 0.5f);
   gl_Position = projection * viewPoint * model * vec4(vertexPosition, 1.0f);
}
