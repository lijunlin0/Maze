#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"Map.h"
//����ջ�ڴ�
#pragma comment(linker, "/STACK:1073741824")
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//����ϵͳʱ��ı���������
	initgraph(159*Map::BLOCKSIZE, 119*Map::BLOCKSIZE);
	setfillcolor(WHITE);
	fillrectangle(0, 0, Map::WIDTH * Map::BLOCKSIZE, Map::HEIGHT * Map::BLOCKSIZE);
	Map m;
	POINT start;
	start.x = 0;
	start.y = 0;
	//m.find_next(start);-----���ݷ�
	m.find_next_2(start);//---����
	m.draw();
	system("pause");
	return 0;
}