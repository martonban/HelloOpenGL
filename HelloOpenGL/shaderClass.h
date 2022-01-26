#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader{
public:
	// Ezzel lehet hivatkozni a Shader Programra
	GLuint ID;


	// Ez a Konstruktora a Shader Programnak, ami megkap ket kulonbozo Shader File-t
	Shader(const char* vertexFile, const char* fragmentFile);

	// Aktivalja a Shader Programot
	void Activate();

	// Torli a Shader Programot
	void Delete();
};
#endif


