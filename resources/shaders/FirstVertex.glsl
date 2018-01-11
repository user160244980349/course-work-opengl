#version 450 core

in vec3 position;
in vec3 normal;
in vec2 uv;
in vec3 tangent;
in vec3 bitangent;

out vec3 fNormal;
out vec2 fUv;
out vec3 fTangent;
out vec3 fBitangent;

uniform mat4 projection;
uniform mat4 viewPoint;
uniform mat4 model;

void main() {
   fUv = uv;
   gl_Position = projection * viewPoint * model * vec4(position, 1.0f);
}
