/*
제목: 케익 배달
번호: 2159번
난이도: 골드 3

문제
N명의 고객에게 케익을 배달하는데, 주문이 들어온 순서대로 배달되기를 원한다.
100000 * 100000 좌표에 고객과 현재 위치가 주어진다.
상하좌우로만 움직일 수 있으며 고객위치에 가거나, 상하좌우 위치까지 가야한다.
최단거리를 이동하여 배달을 끝낼 수 있도록 최단거리를 계산하라.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100001

// 전역 변수 선언
int N;
std::pair<int, int> st;
std::pair<int, int> clients[MAX][5];
long long dp[MAX][5];
int dirA[5] = {0, 0, 0, 1, -1};
int dirB[5] = {0, 1, -1, 0, 0};

// 기본 함수
void input();
void findAnswer();
void checkDist(int i, int j);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N;
	std::cin >> st.first >> st.second;
	for (int i = 0; i < N; i++) {
		std::cin >> clients[i][0].first >> clients[i][0].second;
		for (int j = 1; j < 5; j++) {
			clients[i][j].first = clients[i][0].first + dirA[j];
			clients[i][j].second = clients[i][0].second + dirB[j];
		}
	}
}

void findAnswer() {
	for (int k = 0; k < 5; k++) {
		int endA = clients[0][k].first;
		int endB = clients[0][k].second;
		dp[0][k] = std::abs(st.first - endA) + std::abs(st.second - endB);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			checkDist(i, j);
		}
	}
	long long minDist = 2e12;
	for (int i = 0; i < 5; i++) {
		if (minDist > dp[N - 1][i]) {
			minDist = dp[N - 1][i];
		}
	}
	std::cout << minDist << std::endl;
}

void checkDist(int i, int j) {
	int endA = clients[i][j].first;
	int endB = clients[i][j].second;
	long long minDist = 2e12;
	for (int k = 0; k < 5; k++) {
		int startA = clients[i - 1][k].first;
		int startB = clients[i - 1][k].second;
		long long curDist = std::abs(startA - endA) + std::abs(startB - endB) + dp[i - 1][k];
		if (minDist > curDist) {
			minDist = curDist;
		}
	}
	dp[i][j] = minDist;
}