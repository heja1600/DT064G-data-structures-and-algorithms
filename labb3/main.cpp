
#include <iostream>
#include <vector>
#include "primes.h"
#include "time.h"




template<typename T>
void print(T begin, T end) {
	for (auto it = begin; it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(){
	time_measurements measure_object;
	return measure_object.exec();
}