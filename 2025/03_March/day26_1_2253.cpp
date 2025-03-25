/*
제목: 점프
번호: 2253번
난이도: 골드 4

문제
처음엔 한 칸 점프 -> 그 후에는 x-1, x, x+1 점프 가능
너무 작은 돌은 점프할 수가 없다.
1번 돌에서 n번 돌까지 최소 점프 횟수 구하기
0 1 0 2 0 -1 3 0 0 4 -1 0 0 5 0 -1 0 0 6
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

// 기본 상수 선언
#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
#define MAX 10001

// input 변수 선언
int n, m;
std::vector<int> rock(MAX);
std::vector<std::vector<int>> dp(MAX, std::vector<int>(501));
int res;

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

// 추가 함수
int find(int cur, int prev);

// main 함수
int main(void) {
	FASTIO
	init();
	input();
	setting();
	findAnswer();
}

void init() {
	
}

void input() {
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		std::cin >> k;
		rock[k] = -1;
	}
}

void setting() {
	res = find(1, 0);
	if (res == MAX) {
		res = -1;
	}
}

void findAnswer() {
	std::cout << res << std::endl;
}

int find(int cur, int prev) {
	if (cur == n) { return 0; }
	if (cur > n) { return MAX; }
	if (rock[cur]) { return MAX; }
	if (dp[cur][prev] > 0) { return dp[cur][prev]; }

	int &x = dp[cur][prev];
	x = MAX;

	if (prev > 0) {
		x = std::min(x, find(cur + prev, prev) + 1);
	}
	if (prev - 1 > 0) {
		x = std::min(x, find(cur + prev - 1, prev - 1) + 1);
	}
	x = std::min(x, find(cur + prev + 1, prev + 1) + 1);

	return x;
}