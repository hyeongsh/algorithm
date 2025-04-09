/*
제목: 수상 택시
번호: 2836번
난이도: 골드 3

문제
0번 집에서 보트를 이용해서 사람들을 운송해야 한다.
M번 집까지 가는 길에 사람들 총 N명 태워서 원하는 목적지에 데려다 줘야 한다.

*/

// 라이브러리 설정
#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, M;
std::vector<std::pair<int, int>> vec;

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
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int st, en;
		std::cin >> st >> en;
		if (st > en) {
			vec.push_back({en, st});
		}
	}
}

void setting() {
	std::sort(vec.begin(), vec.end());
}

void findAnswer() {
	long long move = M;
	int size = vec.size();
	int left = 0;
	int right = 0;
	for (int i = 0; i < size; i++) {
		if (vec[i].first > right) {
			move += (2 * (right - left));
			left = vec[i].first;
			right = vec[i].second;
		} else {
			right = std::max(right, vec[i].second);
		}
	}
	move += (2 * (right - left));

	std::cout << move << std::endl;
}
