#include "camera.hpp"
#include "constantes.hpp"
#include <vector>
#include <utility>

void Camera::draw()
{
	//get a view on the cells of the map
	std::vector<CellContent> const& cells = data.map.getCells();
	
	//get the map dimension
	std::pair<int, int> dimension = data.map.getDimension();
	int i = 0, colon = dimension.second;
	
	//clear the window
	window.clear(sf::Color::White);
	
	//draw the map
	for(std::vector<CellContent>::const_iterator 
		it = cells.begin();	it != cells.end();it++, i++)
	{
		CellContent content = *it;
		tile.setPosition((float)((i%colon)*50),
			(float)((i/colon)*50));
		switch(content)
		{
			case WALL:
				tile.setFillColor(sf::Color(100,50,30));
				break;
			case EMPTY:
				tile.setFillColor(sf::Color::White);
				break;
			case SNAKE_BODY:
				tile.setFillColor(sf::Color::Yellow);
				break;
			case SNAKE_HEAD:
				tile.setFillColor(sf::Color(243,206,10));
				break;
			case FOOD:
				tile.setFillColor(sf::Color(243,127,157));
				break;
			default:
				break;
		}
		//draw the tile on the screen
		window.draw(tile);
	}
	//update the window on the screen
	window.display();
}

void Camera::interact()
{
	bool haveChangedOrientation = false;
	//flush the event queue
	while(window.pollEvent(event))
	{
		//Keyboard event
		if(event.type == sf::Event::KeyPressed)
		{
			//verify the key
			switch(event.key.code)
			{
				case sf::Keyboard::Down:
					if(!haveChangedOrientation)
						data.snake.changeDirection(DOWN);
					haveChangedOrientation = true;
					break;
				case sf::Keyboard::Up:
					if(!haveChangedOrientation)
						data.snake.changeDirection(UP);
					haveChangedOrientation = true;
					break;
				case sf::Keyboard::Right:
					if(!haveChangedOrientation)
						data.snake.changeDirection(RIGHT);
					haveChangedOrientation = true;
					break;
				case sf::Keyboard::Left:
					if(!haveChangedOrientation)
						data.snake.changeDirection(LEFT);
					haveChangedOrientation = true;
					break;
				default:
					break;
			}
		}
	}
}
