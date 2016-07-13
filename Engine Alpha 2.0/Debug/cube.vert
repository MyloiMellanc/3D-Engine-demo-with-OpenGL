#version 420

in vec3 cube_vertex;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;


void main()
{
	vec4 wpos = model_matrix * vec4(cube_vertex, 1.0);
	vec4 epos = view_matrix * wpos;
	gl_Position = projection_matrix * epos;

}
