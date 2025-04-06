/*
제목: X와 K
번호: 1322번
난이도: 골드4

문제
X와 K가 주어졌을 때 X + Y = X | Y 를 만족하는 K번째로 작은 자연수 Y를 구하여라

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <cmath>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 32

// 전역 변수 선언
int X, K;
int xBit[MAX];
int kBit[MAX];

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

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
	std::cin >> X >> K;
}

void setting() {
	long long cur = 1;
	int count = 0;
	long long x = X;
	while (x) {
		while (cur * 2 <= x) {
			cur *= 2;
			count++;
		}
		xBit[MAX - 1 - count] = 1;
		x -= cur;
		cur = 1;
		count = 0;
	}

	cur = 1;
	count = 0;
	long long k = K;
	while (k) {
		while (cur * 2 <= k) {
			cur *= 2;
			count++;
		}
		kBit[MAX - 1 - count] = 1;
		k -= cur;
		cur = 1;
		count = 0;
	}
	
}

void findAnswer() {
	std::vector<int> ans(64, 0);
	int x = MAX - 1, k = MAX - 1, a = 63;
	for (; x > 0 || k > 0;) {
		if (xBit[x] == 1) {
			ans[a--] = 0;
			if (x != 0) x--;
		} else if (kBit[k] == 1) {
			ans[a--] = 1;
			if (x != 0) x--;
			k--;
		} else {
			ans[a--] = 0;
			if (x != 0) x--;
			k--;
		}
	}
	long long res = 0;
	for (int i = 0; i < 64; i++) {
		if (ans[i]) {
			res += (long long)std::pow(2, (63 - i));
		}
	}
	std::cout << res << std::endl;
}
