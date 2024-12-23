
#include <iostream>

int main(void) {
	int n, k;
	int ans = 1;
	std::cin >> n >> k;
	if (k > n - k) {
		k = n - k;
	}
	for (int i = 0; i < k; i++) {
		ans *= (n - i);
	}
	for (int i = 0; i < k; i++) {
		ans /= i + 1;
	}
	std::cout << ans << std::endl;
}