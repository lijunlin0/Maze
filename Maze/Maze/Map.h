#pragma once
#include<vector>
#include <graphics.h>

class Map
{
private:
	//��������ת�߼�����
	POINT to_logic(POINT p);
public:
	int cont = 0;
	static const int BLOCKSIZE = 8;
	static const int WIDTH = 159;
	static const int HEIGHT = 119;
	//·
	static const int ROAD = 0;
	//ǽ
	static const int WALL = 1;
	Map();
	//���ݵ��б��ջ
	std::vector<POINT>back_tracking;
	//����
	std::vector<POINT>queue;
	//���߷���
	std::vector<POINT> road;
	//����
	int data[WIDTH][HEIGHT];
	//���ݷ�
	void find_next(POINT p);
	//���з�
	void find_next_2(POINT p);
	//����ǰ���Ŀ�����м������Ϊ·
	void set_center(POINT p,POINT next);
	void draw();
};
