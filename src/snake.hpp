#ifndef SNAKE_DEF
#define SNAKE_DEF
#include <list>
#include "direction.hpp"
#include "constantes.hpp"

class Snake{
	std::list<int> snake;
	int grow, headID, queueID;
	Direction direction;
public:
	Snake(int middleID, Direction const& direction):grow(3),
		headID(middleID), queueID(middleID),
		direction(direction)
	{}

	void move()
	{
		headID += direction.nextID();
		snake.push_back(headID);
		if(grow)
		{
			grow--;
			return;
		}
		queueID = snake.front();
		snake.pop_front();
	}
	
	void changeDirection(Orientation newOrientation)
	{direction.setOrientation(newOrientation);}
	
	void growUp()
	{grow += 3;}
	
	int head() const
	{return headID;}
	
	int queue() const
	{return queueID;}
};

#endif//SNAKE_DEF
