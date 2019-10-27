#ifndef HASH_H
#define HASH_H

#include <vector>


template<typename T>
class hash {
	size_t table_size;
	std::vector<std::vector<T>> hash_table;
public:
	hash():table_size(127){
		hash_table.resize(table_size);
	}
	bool find(T &value) {
		T hash = hash_function(value);
		for (auto e : hash_table[hash]) {
			if (value == e) {
				return true;
			}
		}
		return false;
	}
	void insert(T value) {
		hash_table[hash_function(value)].push_back(value);
	}
	T hash_function(T value) {
		return value%table_size;
	}
};


#endif