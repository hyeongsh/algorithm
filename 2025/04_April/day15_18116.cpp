/*
제목: 로봇 조립
번호: 18116번
난이도: 골드4

문제
robot(I)는 부품 I가 속한 로봇
서로 다른 로봇은 공통 부품을 가지지 않는다.
2가지 지시에 응답해야 한다.
1. 서로 다른 부품 2개를 말해주며, 두 부품은 같은 로봇의 부품이라는 정보를 알려준다.
2. 부품 i에 대해서, 지금까지 알아낸 robot(i)의 부품이 몇 개냐고 물어본다.

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 1000001

// 전역 변수 선언
int N;
int robot[MAX][2];

// 기본 함수
void input();
void findAnswer();
int findUnion(int num);
int getUnionSize(int num);
void makeUnion(int a, int b);

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
	char command;
	for (int i = 0; i < MAX; i++) {
		robot[i][0] = i;
		robot[i][1] = 1;
	}
	for (int i = 0; i < N; i++) {
		std::cin >> command;
		if (command == 'I') {
			int a, b;
			std::cin >> a >> b;
			makeUnion(a, b);
		} else {
			int num;
			std::cin >> num;
			std::cout << getUnionSize(num) << "\n";
		}
	}
}

int findUnion(int num) {
	while (num != robot[num][0]) {
		num = robot[num][0];
	}
	return num;
}

int getUnionSize(int num) {
	num = findUnion(num);
	return (robot[num][1]);
}

void makeUnion(int a, int b) {
	a = findUnion(a);
	b = findUnion(b);	
	if (a == b) {
		return ;
	}
	int small = std::min(a, b);
	int large = std::max(a, b);
	robot[small][0] = large;
	robot[large][1] += robot[small][1];
}