
#include <iostream>

int main(void) {
	int r, c;
	int a, b;
	std::cin >> r >> c;
	std::cin >> a >> b;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < c; k++) {
				for (int l = 0; l < b; l++) {
					char print;
					if (i % 2 == k % 2) {
						print = 'X';
					} else {
						print = '.';
					}
					std::cout << print;
				}
			}
			std::cout << '\n';
		}
	}
}