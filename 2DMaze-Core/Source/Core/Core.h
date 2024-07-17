#pragma once

#include <string>
#include <random>
#include <iostream>

struct Position
{
	int x, y;
	int direction = -1;

	Position(int x, int y);
};

namespace Core {

	extern int mazeWidth;
	extern int mazeHeight;

	extern int xPositionOrigin;
	extern int yPositionOrigin;

	void PrintHelloWorld();
	std::string GenBlankRectangle(int width, int height);

	std::string GenStartingMaze();
	std::string IterateMaze(std::string mazeString);
	Position MoveOrigin();

	void CalcEndpoints(std::string& mazeString);
	std::vector<int> GetEndOfLines(std::string mazeString);
}