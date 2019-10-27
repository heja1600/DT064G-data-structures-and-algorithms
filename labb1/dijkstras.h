#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H
#include <queue>
#include <list>
#include <vector>
#include "matrix.h"



class dijkstras{
	int end, current;
	matrix mx;
	std::list<int> N;
	std::priority_queue<nodeList> neighbours;
public:
	dijkstras(int start, int end, matrix mx);
	void pushAllNeighbours();
	void print_tail();
	bool check(int curr)const;
	bool addUp(int c, node* &n);
	int exec();

};

#endif

