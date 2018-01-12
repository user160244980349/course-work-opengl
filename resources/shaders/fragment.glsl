#version 450 core

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material {
    sampler2D diffuse1;
    sampler2D specular1;
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
    vec3 ambient = light.ambient * texture(material.diffuse1, fUv).rgb;

// diffuse
    vec3 normal = normalize(fNormal);
    vec3 lightDirection = normalize(light.position - fPosition);
    float diffuseK = max(dot(normal, lightDirection), 0.0f);
    vec3 diffuse = light.diffuse * diffuseK * texture(material.diffuse1, fUv).rgb;

// specular
    vec3 viewDirection = normalize(viewPosition - fPosition);
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specularK = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
    vec3 specular = light.specular * specularK * texture(material.specular1, fUv).rgb;

    finalColor = vec4(ambient + diffuse + specular, 1.0f);
}
