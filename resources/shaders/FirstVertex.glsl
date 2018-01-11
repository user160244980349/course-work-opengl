#version 450 core

in vec3 position;
in vec2 UV;

out vec2 fUV;

uniform mat4 projection;
uniform mat4 viewPoint;
uniform mat4 model;

void main() {
   fUV = UV;
   gl_Position = projection * viewPoint * model * vec4(position, 1.0f);
}
