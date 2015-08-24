#ifndef SNAKE_DEF
#define SNAKE_DEF
#include <list>

class Snake{
	std::list<int> snake;
	int grow, headID, queueID, direction;
public:
	Snake(int middleID):grow(3), headID(middleID),
		queueID(middleID), direction(BAS)
	{}

	void move()
	{
		headID += direction;
		snake.push_back(headID);
		if(grow)
		{
			grow--;
			return;
		}
		queueID = snake.front();
		snake.pop_front();
	}
	
	void changeDirection(int newDirection)
	{direction = newDirection;}
	
	void growUp()
	{grow += 3;}
	
	int head() const
	{return headID;}
	
	int queue() const
	{return queueID;}
};

#endif//SNAKE_DEF
