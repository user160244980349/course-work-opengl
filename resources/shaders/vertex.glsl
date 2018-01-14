#version 450 core

struct Light {
    vec3 direction;
    vec3 color;
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

out vec2 TexCoords;
out vec3 TangentLightDir;
out vec3 TangentViewPos;
out vec3 TangentFragPos;

uniform Light light;
uniform Camera camera;
uniform vec3 viewPosition;

void main() {

    vec3 FragPos = vec3(camera.model * vec4(position, 0.0));
    TexCoords = uv;

    vec3 T = normalize(vec3(camera.model * vec4(tangent,   0.0)));
    vec3 B = normalize(vec3(camera.model * vec4(bitangent, 0.0)));
    vec3 N = normalize(vec3(camera.model * vec4(normal,    0.0)));
    mat3 TBN = mat3(
        T.x, B.x, N.x,
        T.y, B.y, N.y,
        T.z, B.z, N.z
    );

    TangentLightDir = TBN * light.direction;
    TangentViewPos  = TBN * viewPosition;
    TangentFragPos  = TBN * FragPos;

    gl_Position = camera.projection * camera.view * camera.model * vec4(position, 1.0f);
}
