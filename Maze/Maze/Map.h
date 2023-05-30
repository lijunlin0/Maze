#pragma once
#include<vector>
#include <graphics.h>

class Map
{
private:
	//像素坐标转逻辑坐标
	POINT to_logic(POINT p);
public:
	int cont = 0;
	static const int BLOCKSIZE = 8;
	static const int WIDTH = 159;
	static const int HEIGHT = 119;
	//路
	static const int ROAD = 0;
	//墙
	static const int WALL = 1;
	Map();
	//回溯点列表堆栈
	std::vector<POINT>back_tracking;
	//队列
	std::vector<POINT>queue;
	//可走方向
	std::vector<POINT> road;
	//数据
	int data[WIDTH][HEIGHT];
	//回溯法
	void find_next(POINT p);
	//队列法
	void find_next_2(POINT p);
	//将当前点和目标点的中间点设置为路
	void set_center(POINT p,POINT next);
	void draw();
};
