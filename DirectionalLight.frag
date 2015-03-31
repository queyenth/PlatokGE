#version 330 core

varying vec2 UV;
varying vec3 Position_worldspace;

uniform sampler2D myTextureSampler;
uniform mat4 MV;

void main() {
	vec4 LightColor = vec4(1, 1, 1, 1);
	float LightPower = 0.7f;

	gl_FragColor = texture2D(myTextureSampler, UV).rgba * vec4(0.1, 0.1, 0.1, 1) + LightColor * LightPower;

	/*
	Point light:
	Cl = color of light
	I0 = power of light
	Kc = constant attenuation
	Kl = linear attenuation
	Kq = quadratic attenuation
	S = distance from light to vertex/fragment/polygon
	I = (I0 * Cl)/(Kc+Kl*d+Kq*d*d)
	But on practice, Kq*d*d - not needed
	I = (I0 * Cl)/(Kc+Kl*d)
	*/
}
