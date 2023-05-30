#include "Map.h"
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
Map::Map()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			data[i][j] = WALL;
		}
	}
	data[0][0] = ROAD;
}

void Map::set_center(POINT p,POINT next)
{
	//�м��
	POINT center = p;
	if (next.x > p.x)
	{
		center.x = p.x + 1;
	}
	else if (next.x < p.x)
	{
		center.x = p.x - 1;
	}
	if (next.y > p.y)
	{
		center.y = p.y + 1;
	}
	else if (next.y < p.y)
	{
		center.y = p.y - 1;
	}
	data[next.x][next.y] = ROAD;
	data[center.x][center.y] = ROAD;
}

//�ҵ���һ��Ŀ���
void Map::find_next(POINT p)
{
	//��һ�����ռ����ܿ��ߵķ���
	//��
	if (p.y-2>=0&&data[p.x][p.y - 2] == WALL)
	{
		POINT t;
		t.x = p.x;
		t.y = p.y - 2;
		road.push_back(t);
	}
	//��
	if (p.x+2<WIDTH&&data[p.x + 2][p.y] == WALL)
	{
		POINT t;
		t.x = p.x + 2;
		t.y = p.y;
		road.push_back(t);
	}
	//��
	if (p.y + 2 < HEIGHT && data[p.x][p.y+2] == WALL)
	{
		POINT t;
		t.x = p.x;
		t.y = p.y + 2;
		road.push_back(t);
	}
	//��
	if (p.x-2>=0&&data[p.x - 2][p.y] == WALL)
	{
		POINT t;
		t.x = p.x - 2;
		t.y = p.y;
		road.push_back(t);
	}
	//�ڶ��������ռ��ķ�����ѡ��һ������
	//�����·
	if (road.size() != 0)
	{
		int num = rand() % road.size();
		back_tracking.push_back(p);
		POINT target = road[num];
		road.clear();
		//�м��
		POINT center=p;
		set_center(p, target);
		find_next(target);
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

void Map::find_next_2(POINT p)
{
	//����ƫ��ֵ���÷���
	auto direction = [&](POINT begin,int x,int y)
	{
		POINT next;
		next.x = begin.x + x;
		next.y = begin.y + y;
		if (next.y >= 0&& next.x < WIDTH && next.y < HEIGHT && next.x >= 0 &&data[next.x][next.y] == WALL)
		{
			queue.push_back(next);
			set_center(begin, next);
		}
	};
	queue.push_back(p);
	
	while(queue.size()!=0)
	{
		std::random_shuffle(queue.begin(), queue.end());
		POINT begin = queue[0];

		std::vector<int> nums;
		for (int i = 0; i < 4; i++)
		{
			nums.push_back(i);
		}
		for (int i = 0; i < 4; i++)
		{
			switch (nums[i])
			{
			case 0:direction(begin,0,-2); break;//��
			case 1:direction(begin,2,0); break;//��
			case 2:direction(begin,0,+2); break;//��
			case 3:direction(begin,-2,0); break;//��
			}
		}
		nums.clear();
		queue.erase(queue.begin());
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
				setfillcolor(BLACK);
				solidrectangle(i*BLOCKSIZE,j* BLOCKSIZE,(i + 1)* BLOCKSIZE,(j+1)* BLOCKSIZE);
			}
		}
	}
}
