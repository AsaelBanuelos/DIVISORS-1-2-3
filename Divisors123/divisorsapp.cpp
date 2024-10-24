#include <vector>
#include <iostream>
#include "Benchmark.h"

std::vector<long long> divisors1(long long n);
std::vector<long long> divisors2(long long n);
std::vector<long long> divisors3(long long n);


void printVector(std::vector<long long> vec);

int main() {
	long long input = 1e6;
	int counter = 6;

	for (int i = 1; i <= 5; i++) {

		{
			Benchmark<std::chrono::microseconds> t;
			std::cout << "FUNC DIVISORS 1: VALUE " << input << " 1e " << counter << std::endl;
			std::vector<long long> div1 = divisors1(input);
			std::cout << "Time for divisors1: " << t.elapsed() << " microseconds" << std::endl;
		}

		{
			Benchmark<std::chrono::microseconds> t;
			std::cout << "FUNC DIVIDORS 2:  VALUE " << input << " 1e " << counter << std::endl;
			std::vector<long long> div2 = divisors2(input);
			std::cout << "Time for divisors2: " << t.elapsed() << " microseconds" << std::endl;
		}

		{
			Benchmark<std::chrono::microseconds> t;
			std::cout << "FUNC DIVISORS 3: VALUE" << input << " 1e " << counter << std::endl;
			std::vector<long long> div3 = divisors3(input);
			std::cout << "Time for divisors3: " << t.elapsed() << " microseconds" << std::endl;
			std::cout << std::endl;
		}


		input = input * 10;
		counter++;
	}

	return 0;
}



//ADD THE NUMBERS STARTING FROM 1 TO INPUTLIMIT TO THE ARRAY ONLY WHEN THE i IS DIVISOR OF IT: "RESULT"
std::vector<long long> divisors1(long long n) {

	std::vector<long long> result;

	for (long long i = 1; i <= n; i++) {

		if (n % i == 0) {
			result.push_back(i);
		}
	}
	return result;
}


//ADD THE DIVISORS STARTING FROM 2 TO THE HALF OF THE LIMIT
std::vector<long long> divisors2(long long n) {

	std::vector<long long> result;

	result.push_back(1);

	for (long long i = 2; i <= n / 2; i++) {

		if (n % i == 0) {
			result.push_back(i);
		}
	}
	if (n != 1) result.push_back(n);
	return result;
}


//RETURNS ALL THE DIVISORS OF N, FIRST CALCULATING THE ONES STARTING FROM N TO SQRT(N), AND SEPARATLY THE SQUARES OF THE i WHEN ARE != N
std::vector<long long> divisors3(long long n) {
	std::vector<long long> result1;
	std::vector<long long> result2;

	double sqrtOfN = sqrt(n);

	for (long long i = 1; i <= sqrtOfN; i++) {

		if (n % i == 0) {
			result1.push_back(i);

			if (i * i != n) {
				result2.push_back(n / i);
			}
		}
	}
	std::vector<long long>result(result1);
	for (int i = result2.size() - 1; i >= 0; i--) {
		result.push_back(result2[i]);
	}
	return result;
}



void printVector(std::vector<long long> vec) {
	for (long long i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}