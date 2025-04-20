/*
제목: 머리 톡톡
번호: 1241번
난이도: 골드 5

문제
원탁에 1 ~ N 명이 앉아 있으며 각자 본인의 번호를 부여받음
자신의 머리 위에 1,000,000 이하의 자연수를 적고 자신이 쓴 숫자가 다른 사람이 쓴 숫자의 배수면 머리를 친다
각 사람이 머리를 친 횟수를 구해야 함.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 1000001

// 전역 변수 선언
int N;
int num[100001];
int touch[MAX][2];

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
	for (int i = 0; i < N; i++) {
		int cur;
		std::cin >> cur;
		num[i] = cur;
		touch[cur][0] += 1;
	}
}

void findAnswer() {
	for (int i = 1; i <= MAX; i++) {
		if (touch[i][0]) {
			touch[i][1] += touch[i][0] - 1;
			for (int j = i + i; j < MAX; j += i) {
				touch[j][1] += touch[i][0];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		std::cout << touch[num[i]][1] << "\n";
	}
}
