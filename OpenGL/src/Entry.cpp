#include "Entry.h"

int Start()
{
	GLFWwindow* window = startWindow();
	startRender(window);
	glfwTerminate();
	return 0;
}

GLFWwindow * startWindow()
{
	glewExperimental = true;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
	}

	glfwSwapInterval(1);
	
	return window;
}

void startRender(GLFWwindow* window)
{
	static const float colorBufferData[] = {
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f
	};

	float vertexBufferData[] =
	{
		-0.5f, -0.5f,  0.5f, //0
		 0.5f, -0.5f,  0.5f, //1
		 0.5f,  0.5f,  0.5f, //2
		-0.5f,  0.5f,  0.5f, //3   front end
		-0.5f, -0.5f, -0.5f, //4
		 0.5f, -0.5f, -0.5f, //5
		 0.5f,  0.5f, -0.5f, //6
		-0.5f,  0.5f, -0.5f, //7   back end
		-0.5f, -0.5f,  0.5f,//0 8
		-0.5f,  0.5f,  0.5f,//3 9
		-0.5f, -0.5f, -0.5f,//4 10
		-0.5f,  0.5f, -0.5f,//7 11   left end
		 0.5f, -0.5f,  0.5f,//1 12
		 0.5f,  0.5f,  0.5f,//2 13
		 0.5f, -0.5f, -0.5f,//5 14
		 0.5f,  0.5f, -0.5f,//6 15  right end
		 0.5f, -0.5f,  0.5f,//1 16
		-0.5f, -0.5f,  0.5f,//0 17
		 0.5f, -0.5f, -0.5f,//5 18
		-0.5f, -0.5f, -0.5f,//4 19 bottom end
		 0.5f,  0.5f,  0.5f,//2 20
		-0.5f,  0.5f,  0.5f,//3 21
		 0.5f,  0.5f, -0.5f,//6 22
		-0.5f,  0.5f, -0.5f,//7 23 top end

	};

	float normalsBufferData[] =
	{
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f,
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f
	};

	unsigned int indexBuffer[] =
	{
		0, 1, 2,
		0, 2, 3, //1
		4, 5, 6,
		4, 6, 7, //2
		8, 9, 10,
		9, 10, 11,
		12, 13, 14,
		13, 14, 15,
		16, 17, 18,
		17, 18, 19,
		20, 21, 22,
		21, 22, 23
		/*
		0, 3, 4,
		3, 4, 7, //3
		1, 2, 5,
		2, 5, 6, //4
		1, 0, 5,
		0, 5, 4, //5
		2, 3, 6,
		3, 6, 7 //6
		*/
	};

	//Define Date end
	 //Qube start

	VertexArray va;

	VertexBuffer vb(vertexBufferData, 24 * 3 * sizeof(float));
	VertexBuffer cb(colorBufferData, 24 * 3 * sizeof(float));
	VertexBuffer nb(normalsBufferData, 24 * 3 * sizeof(float));

	VertexBufferLayout layout;

	IndexBuffer ib(indexBuffer, 36);

	VertexBuffer* pVb[] = { &vb, &cb, &nb };

	layout.push<float>(3);
	layout.push<float>(3);
	layout.push<float>(3);
	va.addBuffer(pVb, layout);

	va.unbind();
	vb.unbind();
	ib.unbind();

	//Qube end

	Shader shader("..\\OpenGL\\src\\shader\\vertexShader.glsl", "..\\OpenGL\\src\\shader\\fragmentShader.glsl");

	//MVP Cube start

	Movement movement(window);

	//MVP Cube end
	//Drawing Loop Start

	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE); //Makes holes (doesnt render all triangles)
	glDepthFunc(GL_LESS);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do {
		movement.movementStart();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.bind();
		glm::mat4 mvp = movement.m_MovementData.getMvp();
		glm::mat4 m = movement.m_MovementData.model;
		//Qube Draw
		va.bind();
		ib.bind();

		shader.setUniform1f("lightStrength", 1.0f);
		shader.setUniform3f("lightColor", 1.0f, 1.0f, 0.5f);
		shader.setUniform3f("lightPosition", 1.0f, 1.0f, 1.0f);
		shader.setUniform3f("viewerPosition", movement.m_Position.x, movement.m_Position.y, movement.m_Position.z);
		shader.setUniformMatrix4fv("M", 1, false, m);
		shader.setUniformMatrix4fv("MVP", 1, false, mvp);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);


		//Buffer swap
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	//Drawing Loop end
	//Collection GB

	shader.unbind();
}
