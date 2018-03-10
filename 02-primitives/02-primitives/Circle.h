#ifndef _CIRCLE_INCLUDE
#define _CIRCLE_INCLUDE

#include "ShaderProgram.h"

#pragma once
class Circle
{
public:
	static Circle *createCircle(float x, float y, float r, ShaderProgram &program);
	Circle(float x, float y, float r, ShaderProgram &program);
	void render() const;
	~Circle();

private:
	float pi = acos(-1.0f);
	float resol = pi / 16;
	GLuint vao;
	GLuint vbo;
	GLint posLocation;
};
#endif // _CIRCLE_INCLUDE
