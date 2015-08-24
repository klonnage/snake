#ifndef DIRECTION_DEF
#define DIRECTION_DEF
#include "map.hpp"

class Direction
{
	int up, down, left, right, orientation;
public:
	Direction(Map const& map, int orientation):
		orientation(orientation)
	{
		right = 1, left = -1;
		up = map.getCellID(0, -1);
		down = map.getCellID(0, 1);
	}
	int nextID()const
	{
		switch(orientation)
		{
			case DOWN:
				return down;
				break;
			case LEFT:
				return left;
				break;
			case RIGHT:
				return right;
				break;
			case UP:
				return up;
				break;
			default:
				return 0;
				break;
		}
	}
};

#endif//DIRECTION_DEF
