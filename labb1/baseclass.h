#ifndef BASECLASS_H
#define BASECLASS_H
#include <queue>
#include <stack>    
#include "matrix.h"

// pushes neighours to queue and stack classes
template<typename T>
class baseclass {
	public:
		int end, current;
		matrix mx;
		T neighbours;

		baseclass(int start, int end, matrix mx, T neighbours) :
			mx(mx),current(start),end(end),neighbours(neighbours){
		}
		void pushAllNeighbours(nodeList nl) {
			node* iterateNode = nl.head;
			while (iterateNode) {
				if (!mx.arr[iterateNode->dest].visited) {
					neighbours.push(iterateNode->dest);
				}
				iterateNode = iterateNode->next;
			}
		}
};

#endif
