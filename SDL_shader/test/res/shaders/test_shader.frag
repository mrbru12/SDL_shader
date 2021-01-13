#version 460 core

layout(location = 0) in vec3 frag_color;

layout(location = 0) out vec4 color;

uniform vec4 u_color;

void main()
{
	color = vec4(frag_color, 1.0);
}
