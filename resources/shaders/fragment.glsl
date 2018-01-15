





#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
    vec3 TangentLightPos;
    vec3 TangentViewPos;
    vec3 TangentFragPos;
} fs_in;

uniform sampler2D diffuseMap;
uniform sampler2D normalMap;
uniform samplerCube skybox;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
     // obtain normal from normal map in range [0,1]
    vec3 normal = texture(normalMap, fs_in.TexCoords).rgb;
    // transform normal vector to range [-1,1]
    normal = normalize(normal * 2.0 - 1.0);  // this normal is in tangent space

    // get diffuse color
    vec3 color = texture(diffuseMap, fs_in.TexCoords).rgb;

    // ambient
    vec3 ambient = 0.1 * color;

    // diffuse
    vec3 lightDir = normalize(-fs_in.TangentLightPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;

    // specular
    vec3 viewDir = normalize(fs_in.TangentViewPos - fs_in.TangentFragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

    // reflections
    vec3 intense = normalize(fs_in.TangentViewPos - fs_in.TangentFragPos);
    vec3 ref = reflect(intense, normal);
    vec3 reflection = texture(skybox, ref).rgb;

    vec3 specular = vec3(0.2) * spec;
    FragColor = vec4(ambient + diffuse + specular /*+ reflection*/, 1.0);
}










//#version 450 core
//
//uniform struct Light {
//    vec3 direction;
//    vec3 color;
//} light;
//
//uniform struct Material {
//    sampler2D diffuse;
//    sampler2D specular;
//    sampler2D normal;
//    float ka;
//    float kd;
//    float ks;
//    float s;
//} material;
//
//in vec2 TexCoords;
//in vec3 TangentLightDir;
//in vec3 TangentViewPos;
//in vec3 TangentFragPos;
//
//uniform samplerCube skybox;
//
//out vec4 finalColor;
//
//void main() {
//
//    vec3 color = texture(material.diffuse, TexCoords).rgb;
//    vec3 specularColor = texture(material.specular, TexCoords).rgb;
//    vec3 normal = texture(material.normal, TexCoords).rgb;
//
//// ambient
//    vec3 ambient = (light.color + color) * material.ka;
//
//// diffuse
//    float diff = max(dot(TangentLightDir, normal), 0.0);
//    vec3 diffuse = (light.color + color) * diff * material.kd;
//
//// specular
//    vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
//    vec3 reflectDir = reflect(TangentLightDir, normal);
//    vec3 halfwayDir = normalize(TangentLightDir + TangentFragPos - TangentViewPos);
//    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.s);
//    vec3 specular = (light.color + specularColor) * spec * material.ks;
//
//// reflections
//    vec3 intense = normalize(TangentViewPos - TangentFragPos);
//    vec3 ref = reflect(intense, normal);
//    vec3 reflection = texture(skybox, ref).rgb;
//
//    finalColor = vec4(ambient + diffuse + specular, 0.0f);
//}
