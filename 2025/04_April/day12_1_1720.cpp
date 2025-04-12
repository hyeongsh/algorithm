/*
제목: 타일 코드
번호: 1720번
난이도: 골드 4

문제
1x2사이즈 2x2사이즈 타일로 2xN 크기의 보드를 채운다.
채우는 방식의 개수를 구하라.(좌우 대칭을 이루는 표현은 중복이므로 제외한다.)
1 -> 1
2 -> 3
3 -> 5
4 -> 11
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 31

// 전역 변수 선언
int N;
int board[31] = {0, 1, 3};

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
}

void findAnswer() {
	for (int i = 3; i <= N; i++) {
		board[i] = board[i - 1] + board[i - 2] * 2;
	}
	int res;
	if (N < 3) {
		res = board[N];
	} else if (N % 2) {
		res = (board[N] + board[N / 2]) / 2;
	} else {
		res = (board[N] + board[N / 2] + (board[N / 2 - 1] * 2)) / 2;
	}
	std::cout << res << std::endl;
}
