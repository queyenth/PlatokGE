#version 120

varying vec2 UV;

uniform sampler2D myTextureSampler;

void main() {
	gl_FragColor = texture2D(myTextureSampler, UV).rgba;
}
