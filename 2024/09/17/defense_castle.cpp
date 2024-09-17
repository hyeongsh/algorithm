
#include <iostream>

int map_a[51] = {0, };
int map_b[51] = {0, };

int main(void) {
	int n, m;

	std::cin >> n >> m;
	std::string input;
	for (int i = 0; i < n; i++) {
		std::cin >> input;
		for (int j = 0; j < m; j++) {
			if (input[j] == 'X') {
				map_a[i] = 1;
				map_b[j] = 1;
			}
		}
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		a += (map_a[i] == 0);
	}
	for (int i = 0; i < m; i++) {
		b += (map_b[i] == 0);
	}
	if (a >= b) {
		std::cout << a << std::endl;
	} else {
		std::cout << b << std::endl;
	}
}
