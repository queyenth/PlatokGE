#version 330 core

in vec2 UV;
in vec3 Position_worldspace;

out vec4 color;

uniform sampler2D myTextureSampler;
uniform mat4 MV;

void main() {
	vec4 LightColor = vec4(1, 1, 1, 1);
	float LightPower = 0.7f;

	color = texture2D(myTextureSampler, UV).rgba * vec4(0.1, 0.1, 0.1, 1) + LightColor * LightPower;

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