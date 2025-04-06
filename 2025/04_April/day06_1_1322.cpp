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
#define MAX

// 전역 변수 선언
long long X, K;
long long Y;

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
	for (int i = 0, idx = 0; i < 65; i++) {
		if ((X >> i) & 1LL) continue ;
		if ((K >> idx) & 1LL) Y |= (1LL << i);
		idx++;
	}
}

void findAnswer() {
	std::cout << Y << std::endl;
}
