#include"VBO.h"

// Konstruktor ami legeneralja a Vertex Buffer Objectett es osszelinkeli a vertexekkel.
VBO::VBO(GLfloat* vertices, GLsizeiptr size){
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binda a VBO-t
void VBO::Bind(){
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbind a VBO-t
void VBO::Unbind(){
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Dtorli a VBO-t
void VBO::Delete(){
	glDeleteBuffers(1, &ID);
}