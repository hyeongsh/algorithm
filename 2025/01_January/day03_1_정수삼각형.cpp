/*
1932번 실버1

정수 삼각형을 내려오면서 지나온 값들을 다 더했을 때 가장 큰 값을 골라야함
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> vec(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int x;
			std::cin >> x;
			vec[i].push_back(x);
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			vec[i][j] += std::max(vec[i + 1][j], vec[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << vec[0][0] << std::endl;
}