#include <GL/glew.h>
#include <GL/gl.h>
#include "Circle.h"


Circle *Circle::createCircle(float x, float y, float r, ShaderProgram &program)
{
	Circle *circle = new Circle(x, y, r, program);

	return circle;
}


Circle::Circle(float x, float y, float r, ShaderProgram &program)
{
	int i = 0;
	int size = int((2 * pi) / resol) * 6;
	float *vertices;
	vertices = new float[size];
	for (float alph = 0; alph < 2 * pi; alph += resol) {
		vertices[i] = x;
		i++;
		vertices[i] = y;
		i++;
		vertices[i] = x + r * sin(alph);
		i++;
		vertices[i] = y + r * cos(alph);
		i++;
		vertices[i] = x + r * sin(alph + resol);
		i++;
		vertices[i] = y + r * cos(alph + resol);
		i++;
	}
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2);
}

void Circle::render() const
{
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glDrawArrays(GL_TRIANGLES, 0, int((2 * pi) / resol) * 3);
}


Circle::~Circle()
{
}
