#pragma once

#include <vector>
#include "Renderer.h"

struct VBufferElem
{
	unsigned int type; // OpenGL type GLuint
	unsigned int count; // OpenGL type GLuint
	unsigned char normalized;
};

class VBufferLayout {

public:
	VBufferLayout();

	// Layout templates
	template<typename T>
	void add(unsigned int count);
	
	// Float layout
	template<>
	void add<float>(unsigned int count);

	// Unsigned int layout
	template<>
	void add<unsigned int>(unsigned int count);

	// Unsigned char layout
	template<>
	void add<unsigned char>(unsigned int count);

	// Getters
	unsigned int getStride();
	std::vector<VBufferElem> getElems();
	int getTypeSize(GLenum type);

private:
	std::vector<VBufferElem> m_Elems;
	unsigned int m_Stride;

};