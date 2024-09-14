
#include <iostream>

int main(void) {
	int N;
	int measure;
	int min = 2147483647;
	int max = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> measure;
		if (measure > max) {
			max = measure;
		}
		if (measure < min) {
			min = measure;
		}
	}
	std::cout << max * min << std::endl;
}