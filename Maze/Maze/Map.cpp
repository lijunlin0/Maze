#include "Map.h"

Map::Map()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			data[i][j] = ROAD;
		}
	}
}

//找到下一个目标点
void Map::find_next(POINT p)
{
	//第一步：收集四周可走的方向
	//上
	if (data[p.x][p.y - 2] == ROAD)
	{
		POINT t;
		t.x = p.x;
		t.y = p.y - 2;
		road.push_back(t);
	}
	//右
	else if (data[p.x + 2][p.y] == ROAD)
	{
		POINT t;
		t.x = p.x + 2;
		t.y = p.y;
		road.push_back(t);
	}
	//下
	else if (data[p.x][p.y+2] == ROAD)
	{
		POINT t;
		t.x = p.x;
		t.y = p.y + 2;
		road.push_back(t);
	}
	//左
	else if (data[p.x - 2][p.y] == ROAD)
	{
		POINT t;
		t.x = p.x - 2;
		t.y = p.y;
		road.push_back(t);
	}
	//第二步：在收集的方向中选择一个方向
	//如果有路
	if (road.size() != 0)
	{
		int num = rand() % road.size();
		back_tracking.push_back(road[num]);
		POINT center=road[num];
		if (road[num].x > p.x)
		{
			center.x = p.x + 1;
		}
		else if (road[num].x < p.x)
		{
			center.x = p.x - 1;
		}
		if (road[num].y > p.y)
		{
			center.y = p.y + 1;
		}
		else if (road[num].y < p.y)
		{
			center.y = p.y - 1;
		}
		data[road[num].x][road[num].y] = ROAD;
		data[center.x][center.y] = ROAD;
		find_next(road[num]);
	}
	else
	{
		back_tracking.pop_back();
		if (back_tracking.size() > 0)
		{
			find_next(back_tracking[back_tracking.size() - 1]);
		}
	}
}

void Map::draw()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (data[i][j]==ROAD)
			{
				setfillcolor(WHITE);
				fillrectangle(i*BLOCKSIZE,j* BLOCKSIZE,(i + 1)* BLOCKSIZE,(j+1)* BLOCKSIZE);
			}
		}
	}
}
