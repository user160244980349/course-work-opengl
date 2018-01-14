#version 450 core

in vec3 fPosition;

uniform samplerCube skybox;

out vec4 finalColor;

void main()
{
    finalColor = texture(skybox, fPosition);
}