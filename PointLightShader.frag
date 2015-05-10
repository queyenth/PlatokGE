#version 120

varying vec2 UV;
varying vec3 Position_worldspace;

uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

void main() {
	vec4 LightColor = vec4(1, 1, 1, 0);
	float LightPower = 50.0f;

	float Kc = 0;
	float Kl = 1;
	float distance = length(LightPosition_worldspace - Position_worldspace);

	gl_FragColor = texture2D(myTextureSampler, UV).rgba +
	        (LightColor * LightPower)/(Kc+Kl*distance);
}
