#version 330 core

in vec3 fragmentColor;
in vec3 normal_cameraspace;
in vec3 lightDirection_cameraspace;
in float fragmentLightColor;
in float fragemntLightPower;

out vec3 color;

void main()
{
	vec3 n = normalize( normal_cameraspace );
	vec3 l = normalize( lightDirection_cameraspace );

	float cosTheta = clamp(dot(n , l), 0, 1);

	color = fragmentColor * fragmentLightColor * fragemntLightPower; //* cosTheta; // / (distance * distance );
}