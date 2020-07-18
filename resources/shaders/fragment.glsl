#version 450 core

in vec3 FragPos;
in vec2 TexCoords;
in vec3 TangentLightPos;
in vec3 TangentViewPos;
in vec3 TangentFragPos;

out vec4 FragColor;

uniform vec3 ka;
uniform vec3 kd;
uniform vec3 ks;
uniform float s;

uniform vec3 lightColor;
uniform float lightIntense;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;
uniform sampler2D specularMap;

void main()
{
    vec3 diffusePart = texture(diffuseMap, TexCoords).rgb;
    vec3 specularPart = texture(specularMap, TexCoords).rgb;
    vec3 normal = texture(normalMap, TexCoords).rgb * 2.0f - 1.0f;

    // ambient
    vec3 ambient = ka * diffusePart;

    // diffuse
    vec3 lightDir = normalize(-TangentLightPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * kd * diffusePart;

    // specular
    vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), s);
    vec3 specular = spec * ks * specularPart;

    FragColor = mix(vec4(ambient + diffuse + specular, 1.0f), vec4(lightColor, 1.0f), lightIntense);
}