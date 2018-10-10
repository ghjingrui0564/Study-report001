#include<glad\glad.h>
#include<GLFW\glfw3.h>


#include<iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const char *vertexShaderSource = 
"#version 330 core\n"
"layout(location=0) in vec3 aPos;\n"
"void main(){\n"
"gl_Position=vec4(aPos,1.0);\n"
"}\0";
const char *fragmentShaderSource1 =
"#version 330 core\n"
"out vec4 Fragcolor;\n"
"void main(){\n"
"Fragcolor=vec4(0.6f,0.2f,0.6f,1.0f);\n"
"}\n\0";
const char *fragmentShaderSource2 =
"#version 330 core\n"
"out vec4 Fragcolor;\n"
"void main(){\n"
"Fragcolor=vec4(0.9f,0.3f,0.4f,1.0f);\n"
"}\n\0";

int main()
{	
	//glfw:initialize and configure
	//-----------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create window
	//-------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "rectangle", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "failed to initialized glad" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//create our first shaderprogram
	//------------------------
	//vertex shader1
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "error of shader compilation:" << infoLog << std::endl;
	}
	//fragment shader1
	int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader1);
	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
		std::cout << "error of shader compilation:" << infoLog << std::endl;
	}
	//our shader program1
	int shaderProgram1 = glCreateProgram();
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
		std::cout << "error of program linking:" << infoLog << std::endl;
	}

	//create our second triangle
	//--------------------------
	int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader2);
	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
		std::cout << "error of shader compilation:" << infoLog << std::endl;
	}
	//our shader program2
	int shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, vertexShader);
	glAttachShader(shaderProgram2, fragmentShader2);
	glLinkProgram(shaderProgram2);
	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
		std::cout << "error of program linking:" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader1);
	glDeleteShader(fragmentShader2);

	//create our second shaderprogram
	//-------------------------------
	//set up vertex data and configure vertex attributes
	//--------------------------------------------------
	float vertices[] = {
		0.5f,  0.5f, 0.0f,  // top right
		0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f  // top left
	};   
	unsigned int indices1[] = {
		0,1,3,	//first triangle
	};
	unsigned int indices2[] = {
		1,2,3	//second triangle
	};

	unsigned int VAO1, VBO1, EBO1;
	unsigned int VAO2, VBO2, EBO2;
	
	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	glGenBuffers(1, &EBO1);

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);
	//set first vertex buffers and vertex attributes
	//----------------------------------------

	glBindVertexArray(VAO1);

	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind VBO and VAO
	glBindBuffer(VBO1, 0);
	glBindVertexArray(0);
	
	//set second vertex buffers and vertex attributes
	//----------------------------------------

	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind VBO and VAO
	glBindBuffer(VBO2, 0);
	glBindVertexArray(0);
	

	//render loop
	//-----------
	while (!glfwWindowShouldClose(window))
	{	
		//input
		processInput(window);

		//render
		//------
		glClearColor(0.2f, 0.3f, 0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw first triangle
		//-------------------
		glUseProgram(shaderProgram1);
		glBindVertexArray(VAO1);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
		//glUseProgram(0);
		//draw second triangle
		//--------------------
		glUseProgram(shaderProgram2);
		glBindVertexArray(VAO2);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(0);
		//glUseProgram(0);
		//wireframe mode
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//de-allocate all resources
	//-------------------------
	glDeleteBuffers(1, &EBO1);
	glDeleteBuffers(1, &VBO1);
	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &EBO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteVertexArrays(1, &VAO2);
	//clearing
	//--------
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
