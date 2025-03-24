/*
제목:
번호:
난이도:

문제

*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 101

// input 변수 선언
int n, k, r;
std::vector<int> map;

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
	std::cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

	}
}

void setting() {

}

void findAnswer() {

}