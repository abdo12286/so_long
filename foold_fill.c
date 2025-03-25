#include "so_long.h"

void foold_fill(int x, int y, char **map)
{
	
	if(map[y][x] == '1' || map[y][x] == 'Q')
		return;
	if(map[y][x] != '1')
		return;
	map[y][x] = 'Q';
	foold_fill(x + 1, y, map);
	foold_fill(x - 1, y, map);
	foold_fill(x, y + 1, map);
	foold_fill(x, y - 1, map);
	return;
}