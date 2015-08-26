#include "data.hpp"
#include "world.hpp"

void World::update()
{
	//replace the head pos of the snake on the map by SNAKE_BODY
	data.map.putCell(data.snake.head(), SNAKE_BODY);
	
	//replace the queue pos of the snake on the map by EMPTY
	data.map.removeCell(data.snake.queue());
	
	//move the snake
	data.snake.move();
	
	/*verify where is the snake's head on the map:
		if the snake's head is on a wall or on a snake's body
			put the game state to 'GameOver'.
		else if the snake's head is on the food
			make grow up the snake
		endif
	*/
	switch(data.map.getCellContent(data.snake.head()))
	{
		case WALL: case SNAKE_BODY:
			state = GAME_OVER;
			break;
		case FOOD:
			data.snake.growUp();
			break;
		default:
			break;
	}
	
	//	put the snake's head at its new pos on the map
	data.map.putCell(data.snake.head(), SNAKE_HEAD);
	
	//	put the snake's queue at its new pos
	data.map.putCell(data.snake.queue(), SNAKE_BODY);
	
	/*if the food is eaten
			generate new food on the map
		endif
	*/
	if(data.map.eatFood())
		data.generator.generate();
}
