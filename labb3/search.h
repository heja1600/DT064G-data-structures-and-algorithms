#ifndef SEARCH_H
#define SEARCH_H
#include "tree.h"
#include "hash.h"
//https ://gist.github.com/toboqus/def6a6915e4abd66e922

template<typename T>
struct linear_search {
	void operator()(T begin, T end, int number) {
		for (; begin != end; begin++) {
			if (*begin == number) {
				break;
			}
		}
	}
};

template<typename T>
struct binary_tree_search {
	bool operator()(T root, int data) {
		//if (root != nullptr) std::cout << "ROOT->DATA:" << root->data << " SEARCH DATA:" << data << std::endl;
		
		if (root == nullptr) return false;
		else if (root->data == data) return true;
		else if (data <= root->data) return (root->left, data);
		else return (root->right, data);
	}
};
template<typename T>
struct binary_treee_search {
	bool operator()(T root, int key)
	{
		// Base Cases: root is null or key is present at root
		if (root == nullptr) return false;
		else if (root->key == key)return true;
		else if (root->key >= key) return (root->left, key);
		else return (root->right, key);
	}
};




template<typename T>
struct hash_search{
	bool operator()(T hash_table_obj, int&data) {
		return hash_table_obj.find(data);
	}
};

template<typename T>
struct binary_search {
	void operator()(T begin, T end, int data) {
		while (begin < end) {
			const T mid = begin + ((end - begin) / 2);
			if (*mid == data) {
				return;
			}
			else if (*mid > data) {
				end = mid;
			}
			else {
				begin = mid + 1;
			}
		}
		return;
	}
};

#endif