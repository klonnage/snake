#include "data.hpp"
#include "world.hpp"
#include "camera.hpp"
#include "direction.hpp"
#include <cstdlib>
#include <utility>
#include <SFML/System.hpp>

int main(int argc, char** argv)
{
	std::pair<int, int> dimension(18, 18);
	//defintion
	Map map(dimension);
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
	Camera camera(data, world);
	
	//make a clock in order to make a pause to have a game in 60Hz
	sf::Clock clock;
	sf::Time delta, fps = sf::milliseconds(100);
	
	//main loop
	while(world.getState() == GAME_CONTINUE)
	{
		//update the game
		world.update();
		//draw a render od the game state
		camera.draw();
		//interact with game
		camera.interact();
		//do a pause
		sf::sleep(fps);
		delta = clock.getElapsedTime();
		//restart the clock
		clock.restart();
	}
	return EXIT_SUCCESS;
}
