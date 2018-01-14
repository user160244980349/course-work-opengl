#version 330 core

struct Light {
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D normal;
    float shininess;
};

in vec3 FragPos;
in vec2 TexCoords;
in vec3 TangentViewPos;
in vec3 TangentFragPos;

uniform samplerCube skybox;
uniform Light light;
uniform Material material;
uniform vec3 viewPosition;

out vec4 finalColor;

void main() {

    vec3 normal = texture(material.normal, TexCoords).rgb;
    normal = normalize(normal * 2.0 - 1.0);

    // get diffuse color
    vec4 color = texture(material.diffuse, TexCoords);

    // ambient
    vec4 ambient = vec4(light.ambient, 0.0f) * color;

    // diffuse
    vec3 lightDir = normalize(light.direction);
    float diff = max(dot(lightDir, normal), 0.0);
    vec4 diffuse = vec4(light.diffuse, 0.0f) * diff * color;

    // specular
    vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
    vec4 specular = vec4(light.specular, 0.0f) * spec;

    // reflections
    vec3 intense = normalize(TangentFragPos - TangentViewPos);
    vec3 ref = reflect(-viewDir, normal);
    vec4 reflection = texture(skybox, ref);

    finalColor = ambient + diffuse + specular + reflection;
}
