#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

const int size = 8;
const int _begin = 0;
const int _end = 6;


// struct who has all neigbour nodes for a node
struct nodeList
{
	bool visited;
	int mass,index;
	struct node *head;
	struct nodeList *camefrom;
	nodeList() :visited(false),mass(0){ };
	bool operator<(const nodeList &o) const
	{
		return mass > o.mass;
	}
};

struct node
{
	int dest, weight;
	struct node* next;
};


//adjecny matrix 
class matrix
{
private:
	int size;
public:
	nodeList* arr;
	matrix(int V);
	node* newNode(int dest, int weight)const;
	void addEdge(int src, int dest, int weight);
	void printMatrix()const;
};

#endif
