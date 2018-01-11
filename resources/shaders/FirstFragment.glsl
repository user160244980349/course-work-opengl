#version 450 core

in vec3 fPosition;
in vec3 fNormal;
in vec2 fUv;
in vec3 fTangent;
in vec3 fBitangent;

out vec4 finalColor;

uniform vec3 viewPosition;
uniform vec3 lightPosition;
//uniform sampler2D fTexture;

void main() {
// object
    vec3 objectColor = vec3(1.0f);

// light
//    vec3 lightPosition = vec3(0.0f);
    vec3 lightColor = vec3(0.9f, 0.1f, 0.8f);

// ambient
    float ambientStrength = 0.4f;
    vec3 ambient = ambientStrength * lightColor;

// diffuse
    vec3 normal = normalize(fNormal);
    vec3 lightDirection = normalize(lightPosition - fPosition);
    float diff = max(dot(normal, lightDirection), 0.0f);
    vec3 diffuse = diff * lightColor;

// specular
    float specularStrength = 0.7f;
    vec3 viewDirection = normalize(viewPosition - fPosition);
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    finalColor = vec4(result, 1.0f);//texture(fTexture, fUv);//
}
