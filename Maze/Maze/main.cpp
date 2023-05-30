#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
//设置栈内存
#pragma comment(linker, "/STACK:1073741824")
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//根据系统时间改变的随机种子
	initgraph(159*Map::BLOCKSIZE, 119*Map::BLOCKSIZE);
	setfillcolor(WHITE);
	fillrectangle(0, 0, Map::WIDTH * Map::BLOCKSIZE, Map::HEIGHT * Map::BLOCKSIZE);
	Map m;
	POINT start;
	start.x = 0;
	start.y = 0;
	//m.find_next(start);-----回溯法
	m.find_next_2(start);//---队列
	m.draw();
	system("pause");
	return 0;
}