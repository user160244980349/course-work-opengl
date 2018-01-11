#version 450 core

in vec2 fUV;
out vec4 finalColor;

uniform sampler2D fTexture;

void main() {
   finalColor = vec4(1.0f, 0.0f, 0.0f, 0.0f);//texture(fTexture, fUV);
}
