#version 330 core

in vec3 fragmentColor;
in vec3 fragmentLightColor;
in vec3 fragmentNormals;
in vec3 fragmentLightPosition;
in float fragmentLightStrength;
in vec3 fragmentPosition;
in vec3 fragmentViewerPosition;

out vec3 color;

void main()
{
	float specularSTR = 1.0f;
	vec3 ambient = fragmentLightColor * fragmentLightStrength;

	vec3 norm = normalize(fragmentNormals);
	vec3 lightDir = normalize(fragmentLightPosition - fragmentPosition);
	
	vec3 viewDir = normalize(fragmentViewerPosition - fragmentPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	vec3 specular = specularSTR * spec * fragmentLightColor;


	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * fragmentLightColor;

	color = (ambient + diffuse + specular) * fragmentColor; 
}