


#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

out VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
    vec3 TangentLightPos;
    vec3 TangentViewPos;
    vec3 TangentFragPos;
} vs_out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
    vs_out.TexCoords = aTexCoords;

    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * aTangent);
    vec3 N = normalize(normalMatrix * aNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);

    mat3 TBN = transpose(mat3(T, B, N));
    vs_out.TangentLightPos = TBN * lightPos;
    vs_out.TangentViewPos  = TBN * viewPos;
    vs_out.TangentFragPos  = TBN * vs_out.FragPos;

    gl_Position = projection * view * model * vec4(aPos, 1.0);
}









//#version 450 core
//
//struct Light {
//    vec3 direction;
//    vec3 color;
//};
//
//struct Camera {
//    mat4 projection;
//    mat4 view;
//    mat4 model;
//};
//
//in vec3 position;
//in vec3 normal;
//in vec2 uv;
//in vec3 tangent;
//in vec3 bitangent;
//
//out vec2 TexCoords;
//out vec3 TangentLightDir;
//out vec3 TangentViewPos;
//out vec3 TangentFragPos;
//
//uniform Light light;
//uniform Camera camera;
//uniform vec3 viewPosition;
//
//void main() {
//
//    vec3 FragPos = vec3(camera.model * vec4(position, 0.0));
//    TexCoords = uv;
//
//    vec3 T = normalize(vec3(camera.model * vec4(tangent,   0.0)));
//    vec3 B = normalize(vec3(camera.model * vec4(bitangent, 0.0)));
//    vec3 N = normalize(vec3(camera.model * vec4(normal,    0.0)));
//    mat3 TBN = mat3(
//        T.x, B.x, N.x,
//        T.y, B.y, N.y,
//        T.z, B.z, N.z
//    );
//
//    TangentLightDir = TBN * light.direction;
//    TangentViewPos  = TBN * viewPosition;
//    TangentFragPos  = TBN * FragPos;
//
//    gl_Position = camera.projection * camera.view * camera.model * vec4(position, 1.0f);
//}
