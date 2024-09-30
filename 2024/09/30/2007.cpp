
#include <iostream>

std::string weeks[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	int m, d;
	std::cin >> m >> d;
	int diff = 0;
	for (int i = 0; i < m - 1; i++) {
		diff += month[i];
	}
	diff += d - 1;
	std::cout << weeks[diff % 7] << std::endl;
}