#ifndef MAP_DEF	
#define MAP_DEF
#include <vector>
#include <utility>
#include "constantes.hpp"
#include <iostream>

class Map {
	std::vector<CellContent> cells;
	std::pair<int,int> dimension;
	int foodPos;
public:
	Map(std::pair<int,int> dim=def_dim):dimension(dim),
		cells(dim.first*dim.second, EMPTY), foodPos(0)
	{
		int i=0, j=0;
		for(std::vector<CellContent>::iterator it=cells.begin();
				it!=cells.end();it++, i++)
			//create the map with an outline
			j+=(!(i%dim.second))?1:0,
			*it=(j == 1 or j == dim.first or !(i%dim.second) or
				i%dim.second == dim.second - 1)?WALL : EMPTY;
	}

	//constructor with a reference to the map
	Map(Map const& map):dimension(map.dimension),
		cells(map.dimension.first*map.dimension.second, EMPTY),
		foodPos(map.foodPos)
	{
		//copy the cells of 'map' in our new map
		this->cells.assign(map.cells.begin(), map.cells.end());
	}
	
	//return a std::pair wich contain the dimension of the map
	const std::pair<int,int>& getDimension() const
	{return dimension;}
	
	//return what contain the cell refers by cellID
	CellContent getCellContent(int cellID)const
	{
		return cells[cellID];
	}
	
	//get an id with an absisse (the x) and an orderly (the y)
	int getCellID(int x,int y)const
	{
		return y*dimension.second + x;
	}
	
	//put content at cellID on the map
	void putCell(int cellID,CellContent content)
	{
		cells[cellID] = content;
		if(content == FOOD)
			foodPos = cellID;

	}
	
	//replace what contain the cell refers by cellID by EMPTY
	void removeCell(int cellID)
	{
		cells[cellID] = EMPTY;
	}
	
	//say if the snake ate the food
	bool eatFood()const
	{
		return cells[foodPos] != FOOD;
	}
	
	//get a view on the cells of the map
	std::vector<CellContent> const& getCells()const
	{
		return cells;
	}
};

#endif//MAP_DEF
