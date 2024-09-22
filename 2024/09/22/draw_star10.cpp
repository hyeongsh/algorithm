
#include <iostream>

void recurStar(int n, int curA, int curB);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			recurStar(n, i, j);
		}
		std::cout << '\n';
	}
}

void recurStar(int n, int curA, int curB) {
	if (curA > n / 3 * 1 && curA <= n / 3 * 2 && curB > n / 3 * 1 && curB <= n / 3 * 2) {
		std::cout << " ";
	} else if (n == 3) {
		std::cout << "*";
	} else {
		int next = n / 3;
		recurStar(next, curA % next, curB % next);
	}
}
