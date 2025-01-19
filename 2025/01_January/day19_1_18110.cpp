/*
18110번
solved.ac
실버 4

문제
n개의 15%를 구해서 위 아래로 제외
이후 평균을 구하고
이를 반올림
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());
	int st = std::round(n * 0.15);
	int en = n - st;
	int sum = 0;
	for (int i = st; i < en; i++) {
		sum += vec[i];
	}
	std::cout << std::round(static_cast<float>(sum) / (en - st)) << std::endl;
}