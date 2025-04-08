/*
제목: 문자열 지옥에 빠진 호석
번호: 20166번
난이도: 골드4

문제
상하좌우, 대각선 모든 방향으로 이동 가능함.
이미 왔던 칸 방문 또한 가능.
타일에 적힌 문자들을 결합해 문자열을 생성해야함.
해당 문자열을 몇 개 생성할 수 있는지 구하는 문제
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <map>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정

// 전역 변수 선언
int N, M, K;
std::string tiles[11];
std::string res[1001];
std::map<std::string, int> myMap;
int da[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int db[8] = {0, 0, 1, -1, 1, -1, -1, 1};

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

void checkStr(int a, int b, std::string curStr, int cur);

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
	std::cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		std::cin >> tiles[i];
	}
	for (int i = 0; i < K; i++) {
		std::cin >> res[i];
	}
}

void setting() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::string str;
			str.push_back(tiles[i][j]);
			checkStr(i, j, str, 0);
		}
	}
}

void findAnswer() {
	for (int i = 0; i < K; i++) {
		std::cout << myMap.find(res[i])->second << std::endl;
	}
}

void checkStr(int a, int b, std::string curStr, int cur) {
	if (cur == 5) {
		return ;
	}
	if (myMap.find(curStr) == myMap.end()) {
		myMap.insert({curStr, 1});	
	} else {
		myMap.find(curStr)->second += 1;
	}
	for (int i = 0; i < 8; i++) {
		std::string nextStr = curStr;
		int nextA = a + da[i];
		int nextB = b + db[i];
		if (nextA < 0 || nextA >= N) {
			nextA = (nextA + N) % N;
		}
		if (nextB < 0 || nextB >= M) {
			nextB = (nextB + M) % M;
		}
		nextStr.push_back(tiles[nextA][nextB]);
		checkStr(nextA, nextB, nextStr, cur + 1);
	}
}