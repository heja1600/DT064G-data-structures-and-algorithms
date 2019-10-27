#ifndef PRIMES_H
#define PRIMES_H



struct primes
{
	template<typename T>
	static void generate_primes(T begin, T end) {
		auto max = (end - begin)*11;
		std::vector<bool> primesEratosthenes(max + 1, true);
		*(begin++) = 2;
		for (unsigned long i = 3; i<max; i += 2) {
			if (primesEratosthenes[i] == true) {
				*(begin++) = i;
				if (begin == end) {
					return;
				}
				for (unsigned long j = 2; j*i <= max; j++) {
					primesEratosthenes[j*i] = false;
				}
			}
		}
		return;
	}
};







#endif