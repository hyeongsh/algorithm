
#include <iostream>

int arr[10] = {0, };

int main(void) {
	long long a, b, c;
	std::cin >> a >> b >> c;
	std::string mul = std::to_string(a * b * c);
	for (int i = 0; i < mul.size(); i++) {
		arr[mul[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;
	}
}