
#include <iostream>
#include <cmath>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		char c;
		std::cin >> c;
		long long tmp = 1;
		for (int j = 0; j < i; j++) {
			tmp *= 31;
			tmp %= 1234567891;
		}
		res += (c - 'a' + 1) * tmp;
		res %= 1234567891;
	}
	std::cout << res << std::endl;
}

// (A + B) mod C = (A mod C + B mod C) mod C
// (A * B) mod C = (A mod C * B mod C) mod C

// 31 ^ 1 = 31
// 31 ^ 2 = 961
// 31 ^ 3 = 29,791
// 31 ^ 4 = 923,521
// 31 ^ 5 = 68,629,151
// 31 ^ 6 = 887,503,681
// 31 ^ 7 = 352,120,509
// 31 ^ 8 = 1,039,192,651
// 31 ^ 9 = 116,207,015
// 31 ^ 10 = 1,133,281,683