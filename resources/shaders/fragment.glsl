#version 450 core

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

in vec3 fPosition;
in vec3 fNormal;
in vec2 fUv;
in vec3 fTangent;
in vec3 fBitangent;

uniform Light light;
uniform Material material;
uniform vec3 viewPosition;

out vec4 finalColor;

void main() {

    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, fUv).rgb;

    // diffuse
    vec3 normal = normalize(fNormal);
    // vec3 lightDir = normalize(light.position - FragPos);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, fUv).rgb;

    // specular
    vec3 viewDir = normalize(viewPosition - fPosition);
    vec3 reflectDir = reflect(-light.direction, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular, fUv).rgb;

    vec3 result = ambient + diffuse + specular;
    finalColor = vec4(result, 1.0);
}
