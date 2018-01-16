#version 330 core

in vec3 aPos;

out vec4 FragPosLightSpace;

uniform mat4 lightView;
uniform mat4 lightProjection;
uniform mat4 model;

void main()
{
    FragPosLightSpace = lightProjection * lightView * vec4(aPos, 1.0f);
    gl_Position = lightProjection * lightView * model * vec4(aPos, 1.0f);
}