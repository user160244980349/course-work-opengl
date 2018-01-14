#version 450 core

struct Camera {
    mat4 projection;
    mat4 view;
    mat4 model;
};

in vec3 position;
in vec3 normal;
in vec2 uv;
in vec3 tangent;
in vec3 bitangent;

out vec3 fPosition;
out vec3 fNormal;
out vec2 fUv;
out vec3 fTangent;
out vec3 fBitangent;

uniform Camera camera;

void main() {

    fPosition = position;
    fNormal = mat3(transpose(inverse(camera.model))) * normal;
    fUv = uv;
    fTangent = tangent;
    fBitangent = bitangent;

    gl_Position = camera.projection * camera.view * camera.model * vec4(position, 1.0f);
}
