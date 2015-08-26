#include <SFML/Window/Keyboard.hpp>
#include "interactor.hpp"
#include "constantes.hpp"
#include "snake.hpp"

void Interactor::interact()
{
	//UP
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		snake.changeDirection(UP);
	//DOWN
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		snake.changeDirection(DOWN);
	//LEFT
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		snake.changeDirection(LEFT);
	//RIGHT
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		snake.changeDirection(RIGHT);
}
