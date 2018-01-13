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
    vec3 lightDirection = normalize(-light.direction - fPosition);
    float diffuseK = max(dot(normal, lightDirection), 0.0f);
    vec3 diffuse = light.diffuse * diffuseK * texture(material.diffuse, fUv).rgb;

// specular
    vec3 viewDirection = normalize(viewPosition - fPosition);
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specularK = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.shininess);
    vec3 specular = light.specular * (specularK * texture(material.specular, fUv).rgb);

    finalColor = vec4(ambient + diffuse + specular, 0.0f);
}
