/*
제목: 세훈이의 선물가게
번호: 17225번
난이도: 골드5

문제
파란색 포장을 원할 시 A초, 빨간색 포장을 원할 시 B초
같은 시간에 시작할 시 파란색 포장이 먼저 진행됨
첫 번째 줄에 파란색 포장 개수
두 번째 줄에 포장한 선물 번호를 오름차순
세 번째 줄에 빨간색 포장 개수
네 번째 줄에 포장한 선물 번호를 오름차순
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int A, B, N;
std::vector<int> blue;
std::vector<int> red;
std::queue<std::pair<int, int>> blueQue;
std::queue<std::pair<int, int>> redQue;

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
	std::cin >> A >> B >> N;
	for (int i = 0; i < N; i++) {
		int t, num;
		std::string color;
		std::cin >> t >> color >> num;
		if (color == "B") {
			blueQue.push({t, num});
		} else {
			redQue.push({t, num});
		}
	}
}

void findAnswer() {
	int curTime = 0;
	int curNumber = 1;
	int blueFinish = 0;
	int redFinish = 0;
	while (!blueQue.empty() || !redQue.empty()) {
		// std::cout << blueQue.size() << " " << redQue.size() << std::endl;
		if (!blueQue.empty() && curTime >= blueFinish && curTime >= blueQue.front().first) {
			if (blueQue.front().second == 0) {
				blueQue.pop();
			} else {
				blueQue.front().second -= 1;
				blue.push_back(curNumber++);
				blueFinish = curTime + A;
			}
		} else if (!redQue.empty() && curTime >= redFinish && curTime >= redQue.front().first) {
			if (redQue.front().second == 0) {
				redQue.pop();
			} else {
				redQue.front().second -= 1;
				red.push_back(curNumber++);
				redFinish = curTime + B;
			}
		} else {
			curTime++;
		}
	}
	
	int size = blue.size();
	std::cout << size << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << blue[i] << " ";
	}
	std::cout << std::endl;
	size = red.size();
	std::cout << size << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << red[i] << " ";
	}
	std::cout << std::endl;
}
