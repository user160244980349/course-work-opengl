#version 450 core

in vec3 fPosition;

out vec4 finalColor;

uniform samplerCube skybox;
uniform vec3 lightColor;
uniform float lightIntense;

void main()
{
    finalColor = mix(texture(skybox, fPosition), vec4(lightColor, 1.0f), lightIntense);
}