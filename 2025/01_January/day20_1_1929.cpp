/*
1929번
소수 구하기
실버 3

문제
M 이상 N 이하의 소수를 모두 출력하는 프로그램을 작성
*/

#include <iostream>

int numbers[1000001];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	int m, n;
	std::cin >> m >> n;
	for (int i = 2; i <= n; i++) {
		if (!numbers[i]) {
			for (int j = i + i; j <= n; j += i) {
				numbers[j] = 1;
			}
		}
		if (i >= m && !numbers[i]) {
			std::cout << i << "\n";
		}
	}
}