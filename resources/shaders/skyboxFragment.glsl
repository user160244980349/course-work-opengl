#version 450 core

in vec3 uv;

uniform samplerCube skybox;

out vec4 finalColor;

void main()
{
    finalColor = texture(skybox, uv);
}