#include "data.hpp"
#include "world.hpp"
#include "camera.hpp"
#include "direction.hpp"
#include "interactor.hpp"
#include <cstdlib>
#include <utility>
#include <SFML/System.hpp>

int main(int argc, char** argv)
{
	//defintion
	Map map;
	Direction direction(map, UP);
	//creation of the snake
	std::pair<int, int> dim = map.getDimension();
	int c = dim.second, l = dim.first;
	Snake snake(l*(c/2)+(l+1)/2, direction);
	
	FoodGenerator generator(map);
	
	//generate the food
	map.removeCell(0);
	map.putCell(0, WALL);
	//generator.generate();
	
	Data data(map, snake, generator);
	World world(data);
	Camera camera(data);
	Interactor interactor(snake);
	
	//main loop
	while(world.getState() == GAME_CONTINUE)
	{
		//update the game
		world.update();
		//draw a render od the game state
		camera.draw();
		//interct with game
		interactor.interact();
		//do a pause
		sf::sleep(sf::milliseconds(100));
	}
	return EXIT_SUCCESS;
}
