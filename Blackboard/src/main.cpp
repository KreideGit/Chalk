#include <Core/Application.h>

int main(int argc, char** argv)
{
	Chalk::Settings settings
	{
		.ApplicationName = "Blackboard App",
		.WindowName = "Blackboard",
		.WindowWidth = 2560,
		.WindowHeight = 1440
	};

	Chalk::Application app(settings);
	app.Start();

	return 0;
}