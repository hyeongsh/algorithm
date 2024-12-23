
#include <iostream>

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		std::cin >> a >> b;
		std::cout << lcm(std::max(a, b), std::min(a, b)) << std::endl;
	}
}

// int gcd(int a, int b) { // a가 더 크도록 해야 함.
// 	if (a < b) {
// 		int tmp = a;
// 		a = b;
// 		b = tmp;
// 	}
// 	if (b == 0) {
// 		return a;
// 	} else {
// 		return gcd(b, a % b);
// 	}
// }

// int lcm(int a, int b) {
// 	return (a * b) / gcd(a, b);
// }
