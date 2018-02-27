#include <GL/glew.h>
#include <GL/gl.h>
#include "Circle.h"



Circle::Circle(float x, float y, float r, ShaderProgram &program)
{
	int i = 0;
	int size = int((2 * pi) / (pi / 4));
	float *vertices;
	vertices = new float[size];
	for (float alph = 0; alph < 2 * pi; alph += pi / 4;) {
		vertices[i] = r * sin(alph);
		i++;
		vertices[i] = r * cos(alph);
		i++;
	}
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2);
}

Circle::~Circle()
{
}
