/*
제목: 신을 모시는 사당
번호: 27210번
난이도: 골드5

문제
돌상 N개가 일렬로 놓여 있을 때 가능한 한 많은 금색 돌상들이 같은 방향을 바라보아야 함.
금색 돌상을 칠해야 하는데, 연속해서 칠하는 방법 밖에 사용할 수 없음.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100001

// 전역 변수 선언
int N;
int stoneMax;
int stoneMin;

// 기본 함수
void input();
void findAnswer();

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int dir;
		std::cin >> dir;
		if (dir == 2) {
			dir = -1;
		}
		sum += dir;
		stoneMax = std::max(sum, stoneMax);
		stoneMin = std::min(sum, stoneMin);
	}
}

void findAnswer() {
	std::cout << stoneMax - stoneMin << std::endl;
}