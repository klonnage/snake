#include "foodGenerator.hpp"
#include <vector>
//for random
#include <random>
#include <iostream>

void FoodGenerator::generate()
{
	std::vector<CellContent> cells = map.getCells();
	//browse the map in order to list the empties cells
	std::vector<int> emptiesCells;
	int i = 0;
	for(std::vector<CellContent>::iterator it = cells.begin();
		it != cells.end();it++, i++)
		//if the current cell is empty, add it in emptiesCells
		if(*it == EMPTY)
			emptiesCells.push_back(i);
	//generate the food
	std::random_device random;
	int foodPos = emptiesCells[random()%emptiesCells.size()];
	map.putCell(foodPos, FOOD);
}
