#version 450 core

struct Light {
    vec3 direction;
    vec3 color;
};

struct Material {
    float ka;
    float kd;
    float ks;
    float s;
};

in vec2 TexCoords;
in vec3 TangentLightDir;
in vec3 TangentViewPos;
in vec3 TangentFragPos;

uniform sampler2D normal1;
uniform sampler2D diffuse1;
uniform sampler2D specular1;

uniform Light light;
uniform Material material;
uniform samplerCube skybox;

out vec4 finalColor;

void main() {

    vec3 color = texture(diffuse1, TexCoords).rgb;
    vec3 specularColor = texture(specular1, TexCoords).rgb;
    vec3 normal = texture(normal1, TexCoords).rgb;

// ambient
    vec3 ambient = (light.color + color) * material.ka;

// diffuse
    float diff = max(dot(TangentLightDir, normal), 0.0);
    vec3 diffuse = (light.color + color) * diff * material.kd;

// specular
    vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
    vec3 reflectDir = reflect(TangentLightDir, normal);
    vec3 halfwayDir = normalize(TangentLightDir + TangentFragPos - TangentViewPos);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.s);
    vec3 specular = (light.color + specularColor) * spec * material.ks;

// reflections
    vec3 intense = normalize(TangentViewPos - TangentFragPos);
    vec3 ref = reflect(intense, normal);
    vec3 reflection = texture(skybox, ref).rgb;

    finalColor = texture(normal1, TexCoords);//vec4(ambient + diffuse + specular + reflection, 0.0f);
}
