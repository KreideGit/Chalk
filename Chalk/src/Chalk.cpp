#include "Chalk.h"

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <glm/mat4x4.hpp>
#include <entt.hpp>
#include <stb_image.h>
#include <box2d/b2_world.h>
#include <miniaudio.h>

void SayHi()
{
	b2World world(b2Vec2_zero);
	ma_engine_play_sound(NULL, NULL, NULL);
	stbi_load("Hi", NULL, NULL, NULL, 5);
	entt::make_any<int>();
	gladLoadGL();
	glfwInit();
	ImGui::Begin("Hi");
	glm::abs(5);
	GLFWwindow* window = glfwCreateWindow(1280, 720, "moin", NULL, NULL);
	while(!glfwWindowShouldClose(window))
	{
		
	}
	std::cout << "Hi\n";
}