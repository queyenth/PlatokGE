#version 330 core

in vec2 UV;
in vec3 Position_worldspace;

out vec4 color;

uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

void main() {
	vec4 LightColor = vec4(1, 1, 1, 0);
	float LightPower = 50.0f;

	float Kc = 0;
	float Kl = 1;
	float distance = length(LightPosition_worldspace - Position_worldspace);

	color = texture2D(myTextureSampler, UV).rgba +
	        (LightColor * LightPower)/(Kc+Kl*distance);
}