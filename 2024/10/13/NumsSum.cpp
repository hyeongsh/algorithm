
#include <iostream>

int main(void) {
	long long s;
	std::cin >> s;
	long long sum = 0;
	long long n = 1;
	while (true) {
		sum += n;
		if (sum > s) {
			break ;
		}
		n++;
	}
	std::cout << n - 1 << std::endl;
}

