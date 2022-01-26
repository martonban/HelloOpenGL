#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VAO{
public:
	// Letrehozzuk az ID referenciat a Vertex Array Object-hez
	GLuint ID;

	// Meghivjuk a Konstruktort ami legeneralja a VAO ID-jat
	VAO();


	// Osszelinkeli a VBO-t a VAO-val egy bizonyos Layoutott hasznalva
	void LinkVBO(VBO& VBO, GLuint layout);

	// Binds a VAO-t
	void Bind();
	// Unbind a VAO-t
	void Unbind();
	// Toroljuk a VAO-t 
	void Delete();
};
#endif