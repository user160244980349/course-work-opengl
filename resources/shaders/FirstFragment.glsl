#version 450 core

in vec3 fNormal;
in vec2 fUv;
in vec3 fTangent;
in vec3 fBitangent;

out vec4 finalColor;

uniform sampler2D fTexture;

void main() {
   finalColor = vec4(1.0f, 0.0f, 1.0f, 0.0f);//texture(fTexture, fUv);//
}
