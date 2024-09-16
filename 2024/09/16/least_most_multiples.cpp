
#include <iostream>
#include <algorithm>
#include <cmath>

int gcd(int a, int b) {
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int number[5];
	int ans = 2147483647;
	for (int i = 0; i < 5; i++) {
		std::cin >> number[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				ans = std::min(ans, lcm(number[i], lcm(number[j], number[k])));
			}
		}
	}
	std::cout << ans << std::endl;
}
