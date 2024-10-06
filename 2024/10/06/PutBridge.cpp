
#include <iostream>

long long combination(int n, int m) {
	long long ans = 1;
	if (n > m - n) {
		n = m - n;
	}
	for (int i = 0; i < n; i++) {
		ans *= m - i;
	}
	for (int i = 0; i < n; i++) {
		ans /= i + 1;
	}
	return ans;
}

int main(void) {
	int t;
	int n, m;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> m;
		std::cout << combination(n, m) << "\n";
	}
}
