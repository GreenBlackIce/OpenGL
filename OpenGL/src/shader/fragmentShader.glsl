#version 330 core

in vec3 fragmentColor;
in vec3 fragmentLightColor;
in vec3 fragmentNormals;
in vec3 fragmentLightPosition;
in float fragmentLightStrength;
in vec3 fragmentPosition;

out vec3 color;

void main()
{
	vec3 ambient = fragmentLightColor * fragmentLightStrength;
	
	vec3 norm = normalize(fragmentNormals);
	vec3 lightDir = normalize(fragmentLightPosition - fragmentPosition);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * fragmentLightColor;

	color = (ambient + diffuse) * fragmentColor; 
}