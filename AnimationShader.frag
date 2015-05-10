#version 120

varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirection_cameraspace;

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

	gl_FragColor = MaterialAmbientColor +
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
