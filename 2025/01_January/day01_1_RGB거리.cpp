/*
1149번 실버1

N개의 줄에 RGB 비용 나열
1. 1번째 집 색은 2번째 집 색과 다름
2. n번째 집은 n - 1	번째 집 색과 다름
3. i번째 집은 i - 1, i + 1번째 집 색과 다름
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> vec(n);
	for (int i = 0; i < n; i++) {
		int r, g, b;
		std::cin >> r >> g >> b;
		vec[i].push_back(r);
		vec[i].push_back(g);
		vec[i].push_back(b);
		if (i > 0) {
			vec[i][0] += std::min(vec[i - 1][1], vec[i - 1][2]);
			vec[i][1] += std::min(vec[i - 1][0], vec[i - 1][2]);
			vec[i][2] += std::min(vec[i - 1][0], vec[i - 1][1]);
		}
	}
	std::cout << std::min(std::min(vec[n - 1][0], vec[n - 1][1]), vec[n - 1][2]) << std::endl;
}