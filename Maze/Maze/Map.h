#pragma once
#include<vector>
#include <graphics.h>

class Map
{
private:
	//像素坐标转逻辑坐标
	POINT to_logic(POINT p);
public:
	static const int BLOCKSIZE = 32;
	static const int WIDTH = 39;
	static const int HEIGHT = 29;
	//路
	static const int ROAD = 0;
	//墙
	static const int WALL = 1;
	Map();
	//回溯点列表堆栈
	std::vector<POINT>back_tracking;
	//可走方向
	std::vector<POINT> road;
	int data[WIDTH][HEIGHT];

	//找到下一个目标点
	void find_next(POINT p);

	void draw();
};
