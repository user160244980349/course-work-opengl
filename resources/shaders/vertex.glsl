#version 330 core

struct Light {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

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

out vec3 FragPos;
out vec2 TexCoords;
out vec3 TangentViewPos;
out vec3 TangentFragPos;

uniform Camera camera;
uniform vec3 viewPosition;
uniform Light light;

void main() {

    FragPos = vec3(camera.model * vec4(position, 1.0));
    TexCoords = uv;

    mat3 TBN = transpose(mat3(tangent, bitangent, normal));
    TangentViewPos  = TBN * viewPosition;
    TangentFragPos  = TBN * FragPos;

    gl_Position = camera.projection * camera.view * camera.model * vec4(position, 1.0f);
}
