Attributes
{
	vec4 a_vert  : 0;
	vec4 a_color : 1;
}

Vertex
{
	out vec4 color;

	void main()
	{
		gl_Position = Gem_MVP * a_vert;
		color = a_color;
	}
}

Fragment
{
	in vec4 color;
	out vec4 outColor;

	void main()
	{
		outColor = color;
	}
}
