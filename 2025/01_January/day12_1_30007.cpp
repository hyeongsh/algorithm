#include <iostream>

int main(void) {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, x;
		std::cin >> a >> b >> x;
		std::cout << a * (x - 1) + b << std::endl;
	}
}
