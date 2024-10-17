
#include <iostream>

int main(void) {
	int t;
	std::cin >> t;
	std::cout << std::fixed;
	std::cout.precision(2);
	for (int i = 0; i < t; i++) {
		double d, f, p;
		std::cin >> d >> f >> p;
		std::cout << "$" << d * f * p << std::endl;
	}
}