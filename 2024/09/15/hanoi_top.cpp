
#include <iostream>

void recur_hanoi(int n, std::string st, std::string mid, std::string en);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	int ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		ans = ans + 1 + ans;
	}
	std::cout << ans << std::endl;
	recur_hanoi(n, "1", "2", "3");
}

void recur_hanoi(int n, std::string st, std::string mid, std::string en) {
	if (n == 1) {
		std::cout << st << " " << en << '\n';
	} else {
		recur_hanoi(n - 1, st, en, mid);
		std::cout << st << " " << en << '\n';
		recur_hanoi(n - 1, mid, st, en);
	}
}
