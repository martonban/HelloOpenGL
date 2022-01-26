#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// Vertex Koordinatak
GLfloat vertices[] ={

	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, 
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f
};

// Indexek A haromszogek kirajzolasahoz
GLuint indices[] ={

	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};



int main(){
	// Inicializáljuk a GLFW-t
	glfwInit();

	// Megmondjuk a GLFW-nak hogy melyik OpenGL verziot hasznaljuk
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Megmondjuk a GLFW-nak hogy a Core Profile-t hasznaljuk
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Letrehozzuk az ablakot
	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello OpenGL", NULL, NULL);

	// Megnezzuk, hogy tortent e valami baj a betoltes soran
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Megmutatja az OpenGL-nek hogy erre az ablakra renderelhet
	glfwMakeContextCurrent(window);

	// Betolti a gladet es ezzel az OpenGL-t is
	gladLoadGL();
	
	// Megadjuk az OpenGL-nek, hogy hova mehet a viewport
	// Ebben az esetben x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);


	// Letrehoz egy Shader objectet, es ezzel két shadert be is fog tolteni defualt.vert es default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Legenerálja a Vertex Array Object and bind-olja azt
	VAO VAO1;
	VAO1.Bind();

	// Legenerálja a Vertex Buffer Object es linkeli a vertexekhez
	VBO VBO1(vertices, sizeof(vertices));
	// Legeneralja az Element Buffer Object es linkeli az indexekhez
	EBO EBO1(indices, sizeof(indices));

	// Hozza linkeljuk VBO-t a VAO-hoz
	VAO1.LinkVBO(VBO1, 0);
	// Aztán Unbind-oljuk nehogy veletlenul megvaltoztassuk
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();



	// Main while loop
	while (!glfwWindowShouldClose(window)){
		// Megadjuk a hatterszint
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		// Clean-eljuk a back buffer es hozzadjuk az uj szint
		glClear(GL_COLOR_BUFFER_BIT);

		// Megmondjuk az OpenGL-nek, hogy melyik shader programot akarjuk hasznalni
		shaderProgram.Activate();

		// Bind-oljuk a VAO-t, hogy az OpenGL tudja hasznalni
		VAO1.Bind();

		// Haromszog kent fogunk kirajzoltatni, idexek szama, indexek tipusa, indexek indexe 
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		// Kicsereljuk a back buffert a front bufferre 
		glfwSwapBuffers(window);

		// Gondoskodik minden GLFW eseméynrõl lsd. újraméretezés stb.
		glfwPollEvents();
	}



	// Torol minden objectett amit letrehoztunk
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Torli az ablakot mielot leall a program
	glfwDestroyWindow(window);

	// Leállitja a GLFW-t mielot leall a program
	glfwTerminate();
	return 0;
}