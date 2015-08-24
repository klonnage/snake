#ifndef MAP_DEF
#define MAP_DEF
#include <vector>
#include <utility>
#include "constantes.hpp"

class Map {
	std::vector<CellContent> cells;
	std::pair<int,int> dimension;
	int foodPos;
public:
	Map(std::pair<int,int> dim=default_dim):dimension(dim),
		cells(dim.first*dim.second,0),foodPos(0)
	{
		int i=0, j=0;
		for(std::vector<CellContent>::iterator it=cells.begin();
				it!=cells.end();it++,i++)
				
			j+=(!(i%dim.first))?1:0,
			*it=(j == 1 or j == dim.second or !(i%dim.first) or
				i%dim.first == dim.first-1)?WALL:EMPTY;
	}
	
	const std::pair<int,int>& getDimension() const
	{return dimension;}
	
	CellContent getCellContent(int cellID)const
	{
		return cells[cellID];
	}
	
	int getCellID(int x,int y)const
	{
		return y*dim.first + x;
	}
	
	void putCell(int cellID,CellContent content)
	{
		cells[cellID] = content;
	}
	
	void removeCell(int cellID)
	{
		cells[cellID] = EMPTY;
	}
	
	bool eatFood()const
	{
		return cells[foodPos] != FOOD;
	}
	
	friend class FoodGenerator;
};

#endif//MAP_DEF
