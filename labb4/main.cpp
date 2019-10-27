
// https://www.coders-hub.com/2015/07/red-black-tree-rb-tree-using-c.html#.W22UJegzaUl

// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
#include <vector>
#include <iostream>
#include "red_black_tree.h"



int main() {
	std::vector<int>vec = { 1,1,1,1,1,1,1,1};

	red_black_tree rb_tree;

	for (auto e : vec) {
		rb_tree.insert(e);
	}

	std::cout << "Inoder Traversal of Created Tree\n";
	rb_tree.in_order();

	std::cout << "\n\nLevel Order Traversal of Created Tree\n";
	rb_tree.level_order();
	
	int stop;
	std::cin >> stop;
	return 0;
}