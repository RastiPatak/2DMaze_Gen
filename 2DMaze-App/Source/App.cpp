#include "Core/Core.h"

#include <iostream>

int main()
{
	Core::mazeWidth = 5;
	Core::mazeHeight = 5;

	std::string maze = Core::GenStartingMaze();
	std::cout << maze;
	//std::cout << "---\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "---\n";
		maze = Core::IterateMaze(maze);
		Core::CalcEndpoints(maze);
		std::cout << maze;

	}
}