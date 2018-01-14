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

uniform samplerCube skybox;
uniform Light light;
uniform Material material;
uniform vec3 viewPosition;

out vec4 finalColor;

void main() {

    // ambient
    vec4 ambient = vec4(light.ambient, 1.0f) * texture(material.diffuse, fUv);

    // diffuse
    vec3 normal = normalize(fNormal);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec4 diffuse = vec4(light.diffuse, 1.0f) * diff * texture(material.diffuse, fUv);

    // specular
    vec3 viewDir = normalize(viewPosition - fPosition);
    vec3 reflectDir = reflect(-light.direction, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec4 specular = vec4(light.specular, 1.0f) * spec * texture(material.specular, fUv);

    // reflections
    vec3 intense = normalize(fPosition - viewPosition);
    vec3 ref = reflect(-viewDir, normal);
    vec4 reflection = texture(skybox, ref);

    // bump
//    mat3 TBN = transpose(mat3(fTangent, fBitangent, fNormal));
//    vs_out.TangentLightPos = TBN * lightPos;
//    vs_out.TangentViewPos  = TBN * viewPos;
//    vs_out.TangentFragPos  = TBN * vec3(model * vec4(aPos, 0.0));
//
//    vec3 normals = texture(normalMap, fs_in.TexCoords).rgb;
//    normals = normalize(normals * 2.0 - 1.0);
//    vec3 lightDir = fs_in.TBN * normalize(lightPos - fs_in.FragPos);
//    vec3 viewDir  = fs_in.TBN * normalize(viewPos - fs_in.FragPos);

    finalColor = vec4(1.0f);
    finalColor = mix(finalColor ,ambient, 0.5f);
    finalColor = mix(finalColor ,diffuse, 0.5f);
    finalColor = mix(finalColor ,specular, 0.5f);
//    finalColor = mix(finalColor, bump, 0.5f);
//    finalColor = mix(finalColor, reflection, 0.5f);
}
