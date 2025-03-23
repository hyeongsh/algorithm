/*
섞기 수열
2487번
골드 4

문제
325614 -> 521436 -> 123654

*/

#include <iostream>
#include <vector>

int n;
std::vector<int> move(20001);
std::vector<bool> vis(20001);

int gcd(int a, int b);
int lcm(int a, int b);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> move[i];
	}
	int max = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int k = 0;
			for (int j = i; !vis[j]; j = move[j]) {
				vis[j] = true;
				k++;
			}
			max = lcm(k, max);
		}
	}
	std::cout << max << std::endl;
}

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}