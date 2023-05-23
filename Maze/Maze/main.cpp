#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
using namespace std;

int main()
{
	initgraph(Map::WIDTH*Map::BLOCKSIZE, Map::HEIGHT*Map::BLOCKSIZE);
	Map m;
	POINT p;
	p.x = 0;
	p.y = 0;
	m.find_next(p);
	m.draw();
	system("pause");
	return 0;
}