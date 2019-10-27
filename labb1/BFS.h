#ifndef BFS_H
#define BFS_H

template<typename T>
class BFS : baseclass<T> {
public:
	BFS(int start, int end, matrix mx, T neighbours)
		:baseclass<T>(start, end, mx, neighbours) { 
		exec();
	}

	int exec() {
		while (current != end) {
			mx.arr[current].visited = true;
			pushAllNeighbours(mx.arr[current]);
			current = neighbours.front();
			neighbours.pop();
			std::cout << current;
		}
		return 0;
	} 
};

#endif
