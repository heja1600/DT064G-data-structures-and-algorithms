#include "matrix.h"


matrix::matrix(int size)
{
	this->size = size;
	arr = new nodeList[size];
	for (int i = 0; i < size; i++)
	{
		arr[i].camefrom = nullptr;
		arr[i].head = nullptr;
		arr[i].index = i;
	}	
}


// creates new node
node* matrix::newNode(int dest, int weight)const
{
	node* tempNode = new node;
	tempNode->dest = dest;
	tempNode->weight = weight;
	tempNode->next = nullptr;
	return tempNode;
}

void matrix::addEdge(int start, int dest, int weight)
{
	node* tempNode = newNode(dest, weight); // creates new node for destination
	tempNode->next = arr[start].head; // New node next points at head
	arr[start].head = tempNode;  // tempnode is now the new head

	tempNode = newNode(start, weight); // creates new node for startpos
	tempNode->next = arr[dest].head; // New node next points at head
	arr[dest].head = tempNode; // tempnode is now the new head

}

void matrix::printMatrix()const
{
	
	for (int i = 0; i < size; ++i)
	{
		node* iterateNode = arr[i].head;
		std::cout << "\n (" << i <<")";
		while (iterateNode)
		{
			std::cout << " -> " << iterateNode->dest<<"("<<iterateNode->weight<<")";
			iterateNode = iterateNode->next;
		}
		std::cout << std::endl;
	}
}
/*bool matrix::visited(int dest)const{
	return this->arr[dest].visited;
}*/




