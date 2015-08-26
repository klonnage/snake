#ifndef INTERACTOR_DEF
#define INTERACTOR_DEF
#include "snake.hpp"

//make interaction between player and snake
class Interactor
{
	Snake& snake;
public:
	Interactor(Snake& snake):snake(snake)
	{}
	
	//make the interaction
	void interact();
};

#endif//INTERACTOR_DEF
