#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VBO{
public:

	// Referencia a Vertex Buffer Object-re
	GLuint ID;

	// Konstruktor ami legeneralja a Vertex Buffer Objectett es osszelinkeli a vertexekkel.
	VBO(GLfloat* vertices, GLsizeiptr size);

	// Bind a VBO-t
	void Bind();
	// Unbind a VBO-t
	void Unbind();
	// Toroljuk a VBO-t
	void Delete();
};

#endif