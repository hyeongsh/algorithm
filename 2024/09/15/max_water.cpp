
#include <iostream>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	char pipe1;
	char pipe2;
	int water;
	for (int i = 0; i < n; i++) {
		std::cin >> pipe1 >> pipe2 >> water;
	}
}
