#ifndef FOOD_GENERATOR_DEF
#define FOOD_GENERATOR_DEF
#include "map.hpp"
#include "constantes.hpp"

class FoodGenerator
{
	Map& map;
public:
	FoodGenerator(Map& map):map(map)
	{}
	
	void generate();
};

#endif//FOOD_GENERATOR_DEF
