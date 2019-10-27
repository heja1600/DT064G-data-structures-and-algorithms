#include "dijkstras.h"

dijkstras::dijkstras(int start, int end, matrix mx)
	:current(start), end(end), mx(mx) {
	exec();
	
}

// checks if curr is marked or not
bool dijkstras::check(int curr)const {
	for (auto e : N) {
		if (e == curr) {
			return false;
		}	
	}
	return true;
}

int dijkstras::exec() {
	do{
		
		N.push_back(current);
		pushAllNeighbours();
		current = neighbours.top().index;
		neighbours.pop();
	} while (!neighbours.empty());
	print_tail();
	return 0;
}



void dijkstras::print_tail()const {
	nodeList nl = mx.arr[end];
	std::cout << "\n 5's tail is :";
	while (nl.camefrom) { 
		std::cout <<nl.index<< "("<< nl.mass<< ")" << " -> ";
		end= nl.camefrom->index;
		nl = mx.arr[end];
		
	}
}

// pushes neighbour to queue
void dijkstras::pushAllNeighbours() {
	node*iterateNode =mx.arr[current].head; 
	while (iterateNode) {
		if (check(iterateNode->dest))
		{
			
			if (addUp(current, iterateNode)) {
				std::cout << iterateNode->dest;
				neighbours.push(mx.arr[iterateNode->dest]);
			}
		}
		iterateNode = iterateNode->next;
	}
}

// returns true if the add up was succesful
bool dijkstras::addUp(int c, node*&n) {
	int temp = mx.arr[c].mass + n->weight;
	if (temp < mx.arr[n->dest].mass || mx.arr[n->dest].mass==0) {
		mx.arr[n->dest].mass = temp;
		mx.arr[n->dest].camefrom = &mx.arr[c];
		return true;
	}
	return false;
}
