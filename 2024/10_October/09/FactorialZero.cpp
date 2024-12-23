
#include <iostream>

int main(void) {
	int n;
	int ans = 0;
	std::cin >> n;
	for (int i = n; i > 0; i--) {
		if (i % 125 == 0) {
			ans += 3;
		} else if (i % 25 == 0) {
			ans += 2;
		} else if (i % 5 == 0) {
			ans += 1;
		}
	}
	std::cout << ans << std::endl;
}

