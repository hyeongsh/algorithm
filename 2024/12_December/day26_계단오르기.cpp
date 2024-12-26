/*
2579번 실버 3

계단을 밟으면 그 계단의 점수를 얻게 된다.
1. 계단은 한 계단 또는 두 계단씩 가능
2. 이어지는 세 개 계단을 전부 밟아서는 안된다.
3. 마지막 계단은 반드시 밟아야 한다.

점수의 최댓값 구하기
*/

#include <iostream>
#include <algorithm>

int stairs[301];
int dp[301];

int main(void) {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> stairs[i];
	}
	for (int i = 1; i <= n; i++) {
		int score1 = 0;
		int score2 = 0;
		if (i < 3) {
			score1 = stairs[i - 1];
		} else {
			score1 = stairs[i - 1] + dp[i - 3];
		}
		if (i > 2) {
			score2 = dp[i - 2];
		}
		dp[i] = std::max(score1, score2) + stairs[i];
//		std::cout << i << ": " << dp[i] << std::endl;
	}
	std::cout << dp[n] << std::endl;
}