
#include <iostream>

int main(void) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		std::cin >> tmp;
		sum += tmp * tmp;
	}
	std::cout << sum % 10 << std::endl;
}