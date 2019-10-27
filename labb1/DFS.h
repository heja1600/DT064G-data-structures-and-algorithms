#ifndef DFS_H
#define DFS_H

template<typename T>
class DFS : baseclass<T> {
public:
	DFS(int start, int end, matrix mx, T neighbours) 
		:baseclass<T>(start, end, mx, neighbours){
		exec();
	}

	int exec() {
		while (current != end) {
			mx.arr[current].visited = true;
			pushAllNeighbours(mx.arr[current]);
			current = neighbours.top();
			neighbours.pop();
			std::cout << current;
		}
		return 0;
	}
};


#endif
