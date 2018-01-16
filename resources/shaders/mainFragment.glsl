#version 450 core

in vec3 FragPos;
in vec2 TexCoords;
in vec3 TangentLightPos;
in vec3 TangentViewPos;
in vec3 TangentFragPos;
in vec4 FragPosLightSpace;

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
uniform sampler2D shadowMap;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
    // check whether current frag pos is in shadow
    float shadow = currentDepth > closestDepth  ? 1.0 : 0.0;

    return shadow;
}

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

    float shadow = ShadowCalculation(FragPosLightSpace);
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular));

    FragColor = vec4(lighting, 1.0);//mix(vec4(ambient + diffuse + specular, 1.0f), vec4(lightColor, 1.0f), lightIntense);
}