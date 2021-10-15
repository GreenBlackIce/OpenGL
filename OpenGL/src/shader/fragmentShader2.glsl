#version 330 core


in vec3 fragmentColor;
in vec3 lightDirection_camera;
in vec3 normal_camera;
in vec3 vertexPosition_camera;
in vec3 lightPosition_camera;
in vec3 viewDirection_camera;
in vec3 fragmentVertexPosition;
in vec3 fragmentLightPosition;

uniform float lightStrength;
uniform vec3 lightColor;

out vec3 color;

void main()
{
    // Distance to the light
	//float dista = length( fragmentLightPosition - fragmentVertexPosition );

    vec3 n = normalize(normal_camera);
    vec3 l = normalize(lightDirection_camera);
    n = abs(n);

    vec3 E = normalize(viewDirection_camera);

    vec3 R = reflect(-l,n);

    float cosAlpha = clamp( dot( E,R ), 0,1 );
    
    float cosTheta = clamp( dot(n,l), 0, 1);

    color = fragmentColor * lightStrength 
        + fragmentColor * lightStrength *  lightColor * cosTheta // (dista*dista)
        + fragmentColor * lightStrength *  lightColor * pow(cosAlpha,16) ;// (dista*dista); 
            // (distance(vertexPosition_camera, lightPosition_camera) * distance(vertexPosition_camera, lightPosition_camera));
}