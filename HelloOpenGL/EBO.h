#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO{
public:

	// Referencia az Element Buffer Object-re
	GLuint ID;

	// Konstruktor ami legeneralja az Element Buffer Object-et es osszelinkeli az indexekkel
	EBO(GLuint* indices, GLsizeiptr size);

	// Bind az EBO-t
	void Bind();
	// Unbind az EBO-t 
	void Unbind();
	// Toroljuk az EBO-t
	void Delete();
};

#endif