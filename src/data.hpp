#ifndef DATA_DEF
#define DATA_DEF
#include "snake.hpp"
#include "foodGenerator.hpp"
#include "map.hpp"

struct Data
{
	Map& map;
	Snake& snake;
	FoodGenerator& generator;

	Data(Map& map, Snake& snake, FoodGenerator& generator):
		map(map), snake(snake), generator(generator)
	{}
};

#endif//DATA_DEF
