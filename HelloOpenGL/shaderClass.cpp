#include"shaderClass.h"


// Beolvas egy textfile-bol egy stringbe és visszater vele
std::string get_file_contents(const char* filename){
	std::ifstream in(filename, std::ios::binary);
	if (in){
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}


// Ez a Konstruktora a Shader Programnak, ami megkap ket kulonbozo Shader File-t
Shader::Shader(const char* vertexFile, const char* fragmentFile){

	// Beolvassa vertexFile es a fragmentFile majd azt egy Stringben tarolja
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Atalakitja a shader source Stringet egy character array-ra
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Letrehozza a Vertex Shader Objectet-t es annak a referenciajat 
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Hozzarendeljuk a Vertex Shader Objectet-t a Vertex Shader Source-at
	glShaderSource(vertexShader, 1, &vertexSource, NULL);

	// Leforditjuk a Veretex Shader Kodjat 
	glCompileShader(vertexShader);


	// Letrehozza a Fragment Shader Objectet-t es annak a referenciajat
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Hozzarendeljuk a Fragment Shader Objectet-t a Fragment Shader Source-at
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

	// Leforditjuk a Fragment Shader Kodjat
	glCompileShader(fragmentShader);



	// Letrehozzuk a Shader Program Objectett és annak a referenciajat
	ID = glCreateProgram();


	// Hozzarendeljuk a Vertex es a Fragment Shadert a Shader Programhoz
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);


	// Osszelinekljuk az osszes Shader-t a Shader programban
	glLinkProgram(ID);


	// Toroljuk a mostanra felesleges Vertex es Fragment Shader Objecteket
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

// Aktivalja a Shader Programot 
void Shader::Activate(){
	glUseProgram(ID);
}

// Torli a Shader Programot
void Shader::Delete(){
	glDeleteProgram(ID);
}