/*
제목: 텔레포트 3
번호: 12908번
난이도: 골드 5

문제
현재 위치에서 집까지 이동해야 한다.
상하좌우로 이동할 수 있다 -> 1초
텔레포트는 한 위치에서 다음 위치로 상호 이동 가능하다. (정해져있음) -> 10초
다익스트라 느낌

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
std::vector<std::pair<long long, int>> info(8);
std::vector<std::vector<std::pair<long long, int>>> board(8);
int vis[8];
long long dist[8];

// 기본 함수
void input();
void findAnswer();
void dijkstra();

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> info[0].first >> info[0].second;
	std::cin >> info[1].first >> info[1].second;
	long long dist = std::abs(info[0].first - info[1].first) + std::abs(info[0].second - info[1].second);
	board[1].push_back({dist, 0});
	board[0].push_back({dist, 1});
	for (int i = 2; i < 8; i++) {
		std::cin >> info[i].first >> info[i].second;
		for (int j = i - 1; j >= 0; j--) {
			if (i / 2 == j / 2) {
				board[i].push_back({10, j});
				board[j].push_back({10, i});
			} else {
				dist = std::abs(info[i].first - info[j].first) + std::abs(info[i].second - info[j].second);
				board[i].push_back({dist, j});
				board[j].push_back({dist, i});
			}
		}
	}
}

void findAnswer() {
	// for (int i = 0; i < 8; i++) {
	// 	int size = board[i].size();
	// 	for (int j = 0; j < size; j++) {
	// 		std::cout << "(i, j) " << i << ", " << j << " : ";
	// 		std::cout << board[i][j].first << " " << board[i][j].second << " ";
	// 		std::cout << std::endl;
	// 	}
	// }
	dijkstra();
}

void dijkstra() {
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		long long curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (vis[curNode]) {
			continue ;
		}
		vis[curNode] = 1;
		if (dist[curNode] == 0 || dist[curNode] > curDist) {
			dist[curNode] = curDist;
		}
		for (int i = 0; i < 7; i++) {
			long long nextDist = board[curNode][i].first;
			int nextNode = board[curNode][i].second;
			if (!vis[nextNode]) {
				// std::cout << curNode << " -> " << nextNode << " : " << curDist + nextDist << std::endl;
				pq.push({curDist + nextDist, nextNode});
			}
		}
	}
	std::cout << dist[1] << std::endl;
}
