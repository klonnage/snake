#ifndef WORLD_DEF
#define WORLD_DEF
#include "data.hpp"

enum GameState
{
	GAME_OVER = 0,
	GAME_CONTINUE = 1
};

class World
{
	Data data;
	GameState state;
public:
	//make the world with a data structure
	World(Data const& data):data(data), state(GAME_CONTINUE)
	{}
	
	/*move the snake onto the map and generate the fodd
	if it is necessary*/
	void update();
	
	//return the state of the game
	GameState getState() const
	{
		return state;
	}
};

#endif//WORLD_DEF
