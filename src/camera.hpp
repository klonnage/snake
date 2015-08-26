#ifndef CAMERA_DEF
#define CAMERA_DEF
#include "data.hpp"
#include <SFML/Graphics.hpp>
#include <utility>

class Camera
{
	Data& data;
	sf::RenderWindow window;
	sf::RectangleShape tile;
	std::pair<int, int> const& dimension;
public:
	Camera(Data& data):data(data),
	dimension(data.map.getDimension()),
		window(sf::VideoMode(data.map.getDimension().first * 50,
			data.map.getDimension().second * 50), "Snake 1.0"),
		tile(sf::Vector2f(50.,50.))
	{
		tile.setOrigin(7.5,7.5);
	}
	
	//draw the map onto the screen
	void draw();
};

#endif//CAMERA_DEF
