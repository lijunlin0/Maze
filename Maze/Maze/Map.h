#pragma once
#include<vector>
#include <graphics.h>

class Map
{
private:
	//��������ת�߼�����
	POINT to_logic(POINT p);
public:
	static const int BLOCKSIZE = 32;
	static const int WIDTH = 39;
	static const int HEIGHT = 29;
	//·
	static const int ROAD = 0;
	//ǽ
	static const int WALL = 1;
	Map();
	//���ݵ��б��ջ
	std::vector<POINT>back_tracking;
	//���߷���
	std::vector<POINT> road;
	int data[WIDTH][HEIGHT];

	//�ҵ���һ��Ŀ���
	void find_next(POINT p);

	void draw();
};
