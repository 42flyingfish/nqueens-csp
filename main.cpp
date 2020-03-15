#include <iostream>
#include <chrono>
#include "csp.h"

bool minMax(CSP & problem, const int maxSteps);

int main() {
	std::cout << "Hello world" <<std::endl;
	int counter = 0;
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; ++i) {
		CSP problem;
		if (minMax(problem, 1000)) {
			++counter;
		}
	}
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> dur = stop - start;
	std::cout << "Run time was " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() / 1000<< " ms\n";
	std::cout << counter << "\n";

	return 0;
}

bool minMax(CSP & problem, const int maxSteps) {
	for (int i = 0; i < maxSteps; ++i) {
		if (problem.isSolution()) {
			//std::cout << "Solution was found in " << i << " steps\n";
			return true;
		}
		int column = rand() % 25;
		problem.minimize(column);
	}
	return false;
}
