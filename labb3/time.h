#ifndef TIME_MEASUREMENTS_H
#define TIME_MEASUREMENTS_H
#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <list>
#include <functional>
#include <algorithm>
#include <fstream>
#include <string>
#include "search.h"
#include "primes.h"
#include "tree.h"
#include "hash.h"


using namespace std::chrono;

struct deviation {
	deviation(double time, int amount) :time(time), amount(amount) {

	}
	double time;
	int amount;
};

struct gnuplot {
	void operator()(const std::vector<deviation>&deviation_vec, const std::string &algorithm)const {
		std::ofstream outfile;
		outfile.open("dat\\" + algorithm + ".dat");
		for (auto e : deviation_vec)
			outfile << e.amount << " " << e.time << std::endl;
	}
};

class time_measurements
{
	std::vector<int>vec;
	struct node *root;
	hash <int> hash_table_obj;
	int runs = 5;
	std::vector<int> numbers{ 20000,40000,60000,80000,100000,120000,140000,160000,180000,200000 };
	std::map<int, std::pair<int,std::vector<int>>> primelist;

	std::map<std::string, std::vector<deviation>> deviation_vec;
public:
	time_measurements();
	void fillprimelist();
	int exec(std::string algorithm = "");
	void print(std::string algorithm);
	double deviation_function(std::string algorithm);

	// changes vector size


	// returnerar random prime från vectorn
	template<typename T>
	int random_prime(T begin, T end) {
		return *(begin + (rand() % (end - begin)));
	}

	void fill_tree(int &n) {
		root = nullptr;
		std::vector<int> temp;
		for (auto e : primelist[n].second) {
			temp.push_back(e);
		}
		std::random_shuffle(temp.begin(), temp.end());
		for (auto e: temp) {
			root = insert(root , e);
		}
	}

	void fill_hash(int n) {

		for (int i = 0; i < n;i++) {
			hash_table_obj.insert(primelist[n].second[i]);
		}
	}

	//för trädet
	template<template<typename> typename Functor> void loop_tree_algorithm(std::string &algorithm) {
		for (auto e : numbers) {
			for (int i = 0; i < runs; i++) {
				fill_tree(e);
				run_algorithm<Functor>(root, e, algorithm);
			}
			print(algorithm);
		}
	}

	// hash
	template<template<typename> typename Functor> void loop_hash_algorithm(std::string &algorithm) { 
		for (auto e : numbers) {
			for (int i = 0; i < runs; i++) {
				fill_hash(e);
				run_algorithm<Functor>(hash_table_obj,e, algorithm);
			}
			print(algorithm);
		}
	}

	template<template<typename> typename  Functor,typename T> void run_algorithm(T type, int &n, std::string &algorithm) 	//tree&& tree this function takes operator to algortihm, numbers , what type of algortihm. 
	{
		int r = 98;
		//int r = primelist[n].first;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		Functor<T>()(type, r);
		
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		deviation_vec[algorithm].push_back({ time_span.count(), n });
	}


	

	// binary linear
	template<template<typename> typename Functor> void loop_run_algorithm(std::string &algorithm) {
		for (auto e : numbers) {
			for (int i = 0; i < runs; i++) {
				run_algorithm<Functor>(std::begin(primelist[e].second), std::end(primelist[e].second), e, algorithm);
			}
			print(algorithm);
		}
	}
	

	template<template<typename> typename  Functor, typename  T> void run_algorithm(T begin, T end, int &n, std::string &algorithm) 	//binary linear this function takes operator to algortihm, numbers , what type of algortihm. 
	{
		int r = 98;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		Functor<T>()(begin, end, r);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		deviation_vec[algorithm].push_back({ time_span.count(), n });
	}
};


time_measurements::time_measurements()
	: root(nullptr)
{
	fillprimelist();
}

void time_measurements::fillprimelist() {
	vec.resize(numbers[numbers.size()-1]);
	primes::generate_primes(std::begin(vec), std::end(vec));
	for (auto e : numbers) {
		primelist[e].first = random_prime(std::begin(vec), std::begin(vec) + e);
		for (int i = 0; i < e; i++) {
			primelist[e].second.push_back(vec[i]);
		}
	}
}
int time_measurements::exec(std::string algorithm) {

	algorithm = "linear_search";
	loop_run_algorithm<linear_search>(algorithm);

	algorithm = "binary_search";
	loop_run_algorithm<binary_search>(algorithm);

	algorithm = "binary_tree_search";
	loop_tree_algorithm<binary_treee_search>(algorithm);

	algorithm = "hash_search";
	loop_hash_algorithm<hash_search>(algorithm);





	int stop;
	std::cin >> stop;
	return 0;
}

// https://www.programiz.com/cpp-programming/examples/standard-deviation
double time_measurements::deviation_function(std::string algorithm) {
	double tot_time = 0;
	double std_dev = 0;
	for (auto e : deviation_vec[algorithm]) {
		tot_time += e.time;
	}
	auto n = deviation_vec[algorithm].size();
	auto avg = tot_time / n;
	for (auto e : deviation_vec[algorithm]) {
		std_dev += pow(e.time - avg, 2);
	}
	return sqrt(std_dev / n);
}

void time_measurements::print(std::string algorithm)
{
	/// lägger till i felsökningslistan
	std::cout << "Algorithm: " << algorithm
		<< ", Runs: " << runs
		<< ", Numbers: " << deviation_vec[algorithm].front().amount
		<< ", Time: " << deviation_vec[algorithm].front().time << " seconds, "
		<< "Deviation: " << deviation_function(algorithm) << ", ";
	std::cout << std::endl;
	gnuplot()(deviation_vec[algorithm], algorithm);
	deviation_vec.erase(deviation_vec.begin());
}





// learned me this here https://stackoverflow.com/questions/1282914/pass-pointer-to-template-function-as-function-argument

#endif 