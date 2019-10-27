#include <list>

#include "matrix.h"
#include "baseclass.h"
#include "BFS.h"
#include "DFS.h"
#include "dijkstras.h"




//matrix 1   0-10  size 11
matrix generateNewMatrix1() {
	matrix mx(size);
	mx.addEdge(0, 1, 3);
	mx.addEdge(0, 2, 2);
	mx.addEdge(0, 3, 4);
	mx.addEdge(1, 2, 6);
	mx.addEdge(1, 4, 2);
	mx.addEdge(2, 3, 6);
	mx.addEdge(2, 5, 2);
	mx.addEdge(3, 5, 6);
	mx.addEdge(4, 7, 3);
	mx.addEdge(4, 5, 1);
	mx.addEdge(5, 6, 1);
	mx.addEdge(5, 7, 7);
	mx.addEdge(5, 8, 7);
	mx.addEdge(5, 9, 7);
	mx.addEdge(6, 9, 4);
	mx.addEdge(7, 8, 6);
	mx.addEdge(7, 10, 3);
	mx.addEdge(8, 9, 3);
	mx.addEdge(8, 10, 2);
	mx.addEdge(9, 10, 8);
	return mx;
}

//matrix 2 0-7   size 8
matrix generateNewMatrix2() {
	matrix mx(size);
	mx.addEdge(0, 1, 3);
	mx.addEdge(0, 2, 2);
	mx.addEdge(0, 4, 5);
	mx.addEdge(1, 3, 3);
	mx.addEdge(2, 3, 1);
	mx.addEdge(2, 5, 6);
	mx.addEdge(3, 6, 4);
	mx.addEdge(4, 5, 2);
	mx.addEdge(5, 6, 1);
	mx.addEdge(5, 7, 4);
	mx.addEdge(6, 7, 2);
	return mx;
}
//matrix 1   0-4  size 11
matrix generateNewMatrix3() {
	matrix mx(size);
	mx.addEdge(0, 1, 2);
	mx.addEdge(0, 5, 9);
	mx.addEdge(0, 8, 1);
	mx.addEdge(1, 2, 1);
	mx.addEdge(1, 5, 5);
	mx.addEdge(5, 6, 1);
	mx.addEdge(2, 3, 3);
	mx.addEdge(2, 6, 1);
	mx.addEdge(6, 7, 7);
	mx.addEdge(6, 9, 1);
	mx.addEdge(6, 3, 1);
	mx.addEdge(6, 10, 7);
	mx.addEdge(3, 7, 5);
	mx.addEdge(3, 4, 1);
	mx.addEdge(7, 10, 7);
	mx.addEdge(7, 4, 3);
	mx.addEdge(10, 4, 1);
	mx.addEdge(8, 5, 7);
	mx.addEdge(8, 6, 4);
	mx.addEdge(8, 9, 6);
	mx.addEdge(9, 10, 4);
	return mx;
}

//matrix 1   0-6  size 8
matrix generateNewMatrix4() {
	matrix mx(size);
	mx.addEdge(0, 6, 100);
	mx.addEdge(0, 1, 1);
	mx.addEdge(0, 5, 2);
	mx.addEdge(1, 2, 6);
	mx.addEdge(1, 5, 2);
	mx.addEdge(2, 3, 2);
	mx.addEdge(3, 4, 2);
	mx.addEdge(5, 4, 30);
	mx.addEdge(5, 7, 36);
	mx.addEdge(4, 7, 2);
	mx.addEdge(4, 7, 2);
	mx.addEdge(7, 6, 3);
	return mx;
}
int main(){
	std::queue<int> _queue;
	std::stack<int> _stack;

	matrix mx = generateNewMatrix4();
	mx.printMatrix();




	BFS <std::queue<int>> bfs(_begin, _end, mx, _queue);
	std::cout << std::endl;

	mx = generateNewMatrix4();
	DFS <std::stack<int>> dfs(_begin, _end, mx, _stack);
	std::cout << std::endl;



	mx = generateNewMatrix4();
	dijkstras dij(_begin, _end, mx);


	int stop;
	std::cin >> stop;
	return 0;
}