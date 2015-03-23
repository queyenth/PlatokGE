#version 330 core

in vec2 UV;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

out vec4 color;

uniform sampler2D myTextureSampler;
uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

void main() {
	vec4 LightColor = vec4(1, 1, 1, 1);
	float LightPower = 4.0f;

	vec4 MaterialDiffuseColor = texture2D(myTextureSampler, UV).rgba;
	vec4 MaterialAmbientColor = vec4(0.1, 0.1, 0.1, 1) * MaterialDiffuseColor;
	vec4 MaterialSpecularColor = vec4(0.3, 0.3, 0.3, 0);

	float distance = length(LightPosition_worldspace - Position_worldspace);

	vec3 n = normalize(Normal_cameraspace);
	vec3 l = normalize(LightDirection_cameraspace);
	float cosTheta = dot(n, l);

	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-l, n);
	float cosAlpha = dot(E, R);

	color = MaterialAmbientColor +
	MaterialDiffuseColor * LightColor * LightPower * cosTheta/* / (distance*distance)*/ +
	MaterialSpecularColor * LightColor * LightPower * pow(max(cosAlpha, 0), 5) * clamp(cosTheta, 0, 1)/* / (distance*distance)*/;
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