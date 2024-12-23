
#include <iostream>
#include <string>

int strPlus(int a, int b) {
	return std::strtod((std::to_string(a) + std::to_string(b)).c_str(), 0);
}

int main(void) {
	int arr[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> arr[i];
	}
	std::cout << arr[0] + arr[1] - arr[2] << std::endl;
	std::cout << strPlus(arr[0], arr[1]) - arr[2] << std::endl;
}