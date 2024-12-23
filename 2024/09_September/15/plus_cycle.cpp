
#include <iostream>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	int ans = 0;
	std::cin >> n;
	int first_n = n;
	while (true) {
		ans++;
		int a = (n % 10) * 10;
		int b = ((n / 10) + (n % 10)) % 10;
		n = a + b;
		if (first_n == n) {
			break ;
		}
	}
	std::cout << ans << std::endl;
}
