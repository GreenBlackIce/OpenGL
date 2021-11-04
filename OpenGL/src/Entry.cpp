#include "Entry.h"
#include "Drawer.h"


int Start()
{
	GLFWwindow* window = startWindow();
	startRender(window);
	glfwDestroyWindow(window);
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
	/*
	static const float colorBufferData[] = {
		
		0.5f,  0.7f,  0.0f,
		0.6f,  0.1f,  0.4f,
		0.3f,  0.4f,  0.8f,
		0.8f,  0.5f,  0.2f,
		0.4f,  0.6f,  0.2f,
		0.3f,  0.7f,  0.1f,
		0.5f,  0.7f,  0.7f,
		0.5f,  0.4f,  0.7f,
		0.3f,  0.5f,  0.1f,
		0.4f,  0.5f,  0.7f,
		0.5f,  0.8f,  0.6f,
		0.1f,  0.5f,  0.8f,
		0.0f,  0.1f,  0.5f,
		0.7f,  0.3f,  0.9f,
		0.4f,  0.6f,  0.1f,
		0.6f,  0.9f,  0.1f,
		0.9f,  0.5f,  0.8f,
		0.1f,  0.6f,  0.4f,
		0.9f,  0.5f,  0.0f,
		0.9f,  0.7f,  0.5f,
		0.5f,  0.0f,  0.9f,
		0.2f,  0.3f,  0.5f,
		0.1f,  0.6f,  0.0f,
		0.3f,  0.8f,  0.1f
	};
	
	float vertexBufferData[] = 
	{
		-0.5f,  0.5f,  0.5f, //0
		 0.5f,  0.5f,  0.5f, //1
		-0.5f, -0.5f,  0.5f, //2
		 0.5f, -0.5f,  0.5f, //3   front end
		-0.5f,  0.5f, -0.5f, //4
		 0.5f,  0.5f, -0.5f, //5
		-0.5f, -0.5f, -0.5f, //6
		 0.5f, -0.5f, -0.5f, //7   back end
		-0.5f, -0.5f,  0.5f, //0 8
		-0.5f,  0.5f,  0.5f, //3 9
		-0.5f, -0.5f, -0.5f, //4 10
		-0.5f,  0.5f, -0.5f, //7 11   left end
		 0.5f, -0.5f,  0.5f, //1 12
		 0.5f,  0.5f,  0.5f, //2 13
		 0.5f, -0.5f, -0.5f, //5 14
		 0.5f,  0.5f, -0.5f, //6 15  right end
		 0.5f, -0.5f,  0.5f, //1 16
		-0.5f, -0.5f,  0.5f, //0 17
		 0.5f, -0.5f, -0.5f, //5 18
		-0.5f, -0.5f, -0.5f, //4 19 bottom end
		 0.5f,  0.5f,  0.5f, //2 20
		-0.5f,  0.5f,  0.5f, //3 21
		 0.5f,  0.5f, -0.5f, //6 22
		-0.5f,  0.5f, -0.5f, //7 23 top end
	};

	float normalsBufferData[] =
	{
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f,
		 0.0f,  0.0f, -1.0f, //front
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f,
		 0.0f,  0.0f,  1.0f, //back
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,
		-1.0f,  0.0f,  0.0f,//left
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f,
		 1.0f,  0.0f,  0.0f, //right
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f,
		 0.0f, -1.0f,  0.0f, //bottom
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f,
		 0.0f,  1.0f,  0.0f  //top
	};

	unsigned int indexBuffer[] =
	{
		0, 1, 2,
		1, 2, 3, //1
		4, 5, 6,
		5, 6, 7, //2
		8, 9, 10,
		9, 10, 11, //3
		12, 13, 14,
		13, 14, 15, //4
		16, 17, 18,
		17, 18, 19, //5
		20, 21, 22,
		21, 22, 23  //6 
	};
	

	VertexArray va;
	VertexBuffer vb(vertexBufferData, 72 * sizeof(float));
	VertexBuffer cb(colorBufferData, 72 * sizeof(float));
	VertexBuffer nb(normalsBufferData, 72 * sizeof(float));
	IndexBuffer ib(indexBuffer, 36);

	VertexBufferLayout layout;
	VertexBuffer* pVb[] = { &vb, &cb, &nb};
	
	layout.push<float>(3);
	layout.push<float>(3);
	layout.push<float>(3);
	va.addBuffer(pVb, layout);
	
	va.unbind();
	vb.unbind();
	nb.unbind();
	cb.unbind();
	ib.unbind();
	
	
	VertexArray va2;
	VertexBuffer vb2(vertexBufferData, 24 * 3 * sizeof(float));
	VertexBuffer cb2(colorBufferData, 24 * 3 * sizeof(float));
	VertexBuffer nb2(normalsBufferData, 24 * 3 * sizeof(float));
	VertexBufferLayout layout2;
	IndexBuffer ib2(indexBuffer, 36);
	VertexBuffer* pVb2[] = { &vb2, &cb2, &nb2 };

	layout2.push<float>(3);
	layout.push<float>(3);
	layout.push<float>(3);
	va2.addBuffer(pVb2, layout2);

	va2.unbind();
	vb2.unbind();
	ib2.unbind();
	
	Shader shader("..\\OpenGL\\src\\shader\\vertexShader2.glsl", "..\\OpenGL\\src\\shader\\fragmentShader2.glsl");

	Movement movement(window);
	*/
	

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	ImGui::StyleColorsDark();
	
	Demo::Demo* currentDemo = nullptr;
	Demo::DemoMenu* demoMenu = new Demo::DemoMenu(currentDemo);
	currentDemo = demoMenu;

	demoMenu->registerDemo<Demo::DemoSingleTriangle>("SingleTriangle");
	demoMenu->registerDemo<Demo::DemoSingleTriangleColor>("Triangle with ColorBuffer");
	demoMenu->registerDemo<Demo::DemoClearColor>("ClearColor");
	


	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do {
		
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (currentDemo)
		{
			currentDemo->onUpdate(0.0f);
			currentDemo->onRender();
			ImGui::Begin("Demo");
			if (currentDemo != demoMenu && ImGui::Button("<-"))
			{
				delete currentDemo;
				currentDemo = demoMenu;
			}
			currentDemo->onImGUIRender();
			ImGui::End();
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}
		
		/*
		movement.movementStart();
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.bind();
		glm::mat4 mvp = movement.m_MovementData.getMvp();
		glm::mat4 m = movement.m_MovementData.model;
		glm::mat4 v = movement.m_MovementData.view;

		//va.bind();
		//ib.bind();

		shader.setUniform1f("lightStrength", 1.0f);
		shader.setUniform3f("lightColor", 1.0f, 1.0f, 1.0f);
		shader.setUniform3f("lightPosition", 4.0f, 2.0f, 4.0f);
		shader.setUniformMatrix4fv("M", 1, false, m);
		shader.setUniformMatrix4fv("V", 1, false, v);
		shader.setUniformMatrix4fv("MVP", 1, false, mvp);
		//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
		Drawer::draw(shader, va, ib);
		
		//va2.bind();
		//ib2.bind();
		mvp = mvp::getMvp(mvp::getModel(glm::mat4(1.0f), glm::vec3(4.0f, 2.0f, 4.0f), glm::vec3(0.2f)), movement.m_MovementData.view, movement.m_MovementData.projection);
		shader.setUniformMatrix4fv("MVP", 1, false, mvp);
		//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
		Drawer::draw(shader, va2, ib2);

		//ImGui::Render();
		//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		
		*/
		//Buffer swap
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	delete demoMenu;
	
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	
}