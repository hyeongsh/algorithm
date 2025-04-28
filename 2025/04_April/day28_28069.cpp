/*
제목: 김밥천국의 계단
번호: 28069
난이도: 골드5

문제
계단 한 칸을 올라가거나, i + i/2 로 이동하여 K번째에 정확하게 N개의 계단을 오를 수 있다면 minigimbob 출력

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 2000001

// 전역 변수 선언
int N, K;
int stairs[MAX];

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
	std::cin >> N >> K;
}

void findAnswer() {
	stairs[1] = 1;
	stairs[2] = 2;
	for (int i = 3; i <= N; i++) {
		int down = stairs[i - 1] + 1;
		int magic = (i % 3 < 2) ? stairs[i / 3 * 2 + i % 3] + 1 : 1e9;
		stairs[i] = std::min(down, magic);
	}
	if (stairs[N] <= K) {
		std::cout << "minigimbob" << std::endl;
	} else {
		std::cout << "water" << std::endl;
	}
}