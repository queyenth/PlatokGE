#version 120

varying vec2 UV;

uniform sampler2D myTextureSampler;
uniform float alphaChannel;

void main() {
	float a = alphaChannel;
	gl_FragColor =
	texture2D(myTextureSampler, UV) * vec4(1, 1, 1, a);
}
