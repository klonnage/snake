#ifndef CAMERA_DEF
#define CAMERA_DEF
#include "data.hpp"
#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <utility>

class Camera
{
	Data& data;
	sf::RenderWindow window;
	sf::RectangleShape tile;
	std::pair<int, int> const& dimension;
	sf::Event event;
	World& world;
public:
	Camera(Data& data, World& world):data(data),
	dimension(data.map.getDimension()),
		window(sf::VideoMode(data.map.getDimension().first * 50,
			data.map.getDimension().second * 50), "Snake 1.0"),
		tile(sf::Vector2f(50.,50.)), world(world)
	{
		tile.setOrigin(7.5,7.5);
	}
	
	//draw the map onto the screen
	void draw();
	
	//may interact with the player
	void interact();
};

#endif//CAMERA_DEF
