#version 330

uniform vec2 scale;

in vec2 position;

void main()
{
	gl_Position = vec4(scale * position , 0.0, 1.0);
}
