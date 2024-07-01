#include "Core.h"

#include <iostream>

namespace Core {

	int mazeWidth;
	int mazeHeight;

	int xPositionOrigin;
	int yPositionOrigin;

	void PrintHelloWorld()
	{
		std::cout << "Hello World!\n";
		std::cin.get();
	}

	std::string GenBlankRectangle(int width, int height)
	{
		std::string output;
		for (int i = 0; i < height; i++)
		{
			output += std::string(width, '#') + "\n";
		}
		return output;
	}

	std::string GenStartingMaze()
	{
		int width = Core::mazeWidth;
		int height = Core::mazeHeight;

		char* output = new char[((width + 1) * height) + 1]();
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < (width + 1); j++)
			{
				if (j == width)
					output[(i * (width + 1)) + j] = '\n';
				else if (j == width - 1 && i == height - 1)
					output[(i * (width + 1)) + j] = '#';
				else if (j == width - 1)
					output[(i * (width + 1)) + j] = 'v';
				else
					output[(i * (width + 1)) + j] = '>';
			}
		}
		xPositionOrigin = width - 1;
		yPositionOrigin = height - 1;
		return std::string(output);
	}

	std::string IterateMaze(std::string mazeString)
	{
		char* output = mazeString.data();
		Position newOrigin = MoveOrigin();
		char oldOriginChar = '#';
		switch (newOrigin.direction)
		{
		case 0: 
			oldOriginChar = '>';
			break;
		case 1: 
			oldOriginChar = 'v';
			break;
		case 2:
			oldOriginChar = '<';
			break;
		case 3:
			oldOriginChar = '^';
			break;
		}
		output[(mazeWidth + 1) * yPositionOrigin + xPositionOrigin] = oldOriginChar;
		output[(mazeWidth + 1) * newOrigin.y + newOrigin.x] = '#';
		xPositionOrigin = newOrigin.x;
		yPositionOrigin = newOrigin.y;
		return std::string(output);
	}

	Position MoveOrigin()
	{
		int xPosition = xPositionOrigin;
		int yPosition = yPositionOrigin;

		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 3);

		int direction = dist6(rng);
		switch (direction)
		{
		case 0: 
			if (xPosition >= mazeWidth - 1)
				return MoveOrigin();
			else
				xPosition++;
			break;
		case 1:
			if (yPosition >= mazeHeight - 1)
				return MoveOrigin();
			else
				yPosition++;
			break;
		case 2:
			if (xPosition <= 0)
				return MoveOrigin();
			else
				xPosition--;
			break;
		case 3:
			if (yPosition <= 0)
				return MoveOrigin();
			else
				yPosition--;
			break;
		default:
			std::cout << "Error occured in MoveOrigin()!" << std::endl;
		}
		Position result = Position(xPosition, yPosition);
		result.direction = direction;
		return result;
	}
}

Position::Position(int x, int y) : x(x), y(y) { }
