
#include <iostream>

int gcd(int a, int b) { // a가 더 크도록 해야 함.
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(void) {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << " " << lcm(a, b) << std::endl;
}
