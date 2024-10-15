
#include <iostream>

int main(void) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int sum = 0;
		int cont = 1;
		std::string str;
		std::cin >> str;
		for (char it : str) {
			if (it == 'O') {
				sum += cont++;
			} else {
				cont = 1;
			}
		}
		std::cout << sum << std::endl;
	}
}