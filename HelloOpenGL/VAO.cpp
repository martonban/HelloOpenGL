#include"VAO.h"


// Konstruktor ami legeneralja a VAO ID-jat
VAO::VAO(){
	glGenVertexArrays(1, &ID);
}


// Osszelinkeli a VBO-t a VAO-val egy bizonyos Layoutott hasznalva
void VAO::LinkVBO(VBO& VBO, GLuint layout){
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

// Bind a VAO-t
void VAO::Bind(){
	glBindVertexArray(ID);
}

// Unbind a VAO-t
void VAO::Unbind(){
	glBindVertexArray(0);
}

// Toroljuk a VAO-t
void VAO::Delete(){
	glDeleteVertexArrays(1, &ID);
}