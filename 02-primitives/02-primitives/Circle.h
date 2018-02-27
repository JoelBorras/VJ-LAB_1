#ifndef _CIRCLE_INCLUDE
#define _CIRCLE_INCLUDE

#include "ShaderProgram.h"

#pragma once
class Circle
{
public:
	Circle(float, float, float, ShaderProgram);
	~Circle();

private:
	float pi = acos(-1.0f);
	GLuint vao;
	GLuint vbo;
	GLint posLocation;
};
#endif // _CIRCLE_INCLUDE
