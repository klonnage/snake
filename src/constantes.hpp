#ifndef CONSTANTES_DEF
#define CONSTANTES_DEF
#include <utility>

//content cells
enum CellContent
{
	EMPTY = 0,
	WALL = 1,
	SNAKE_BODY = 2,
	FOOD = 3,
	SNAKE_HEAD = 4
};

//default dimension
extern const std::pair<int, int> def_dim;

//orientation
enum Orientation
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

#endif//CONSTANTES_DEF
