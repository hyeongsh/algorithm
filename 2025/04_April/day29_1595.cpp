/*
제목: 북쪽나라의 도로
번호: 1595번
난이도: 골드 4

문제
특정 도시를 두번 이상 지나가지 않고 모든 도시를 이동할 수 있도록 도로가 설계되어 있음
최대 10000개의 도시가 있으며, 가장 거리가 먼 도시의 거리를 출력한다.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 10001

// 전역 변수 선언
std::vector<std::vector<std::pair<int, int>>> board(MAX);
int visFirst[MAX];
int visSecond[MAX];
int longestNode = 1;
int longestDist = 0;

// 기본 함수
void input();
void findAnswer();
void dijkstra(int start, int *vis);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	int a, b, c;
	while (std::cin >> a >> b >> c) {
		board[a].push_back({c, b});
		board[b].push_back({c, a});
	}
}

void findAnswer() {
	visFirst[1] = 1;
	dijkstra(1, visFirst);
	longestDist = 0;
	visSecond[longestNode] = 1;
	dijkstra(longestNode, visSecond);
	std::cout << longestDist << std::endl;
}

void dijkstra(int start, int *vis) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({0, start});

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		int size = board[curNode].size();
		for (int i = 0; i < size; i++) {
			int nextDist = board[curNode][i].first;
			int nextNode = board[curNode][i].second;
			if (!vis[nextNode]) {
				if (longestDist < curDist + nextDist) {
					longestDist = curDist + nextDist;
					longestNode = nextNode;
				}
				vis[nextNode] = 1;
				pq.push({curDist + nextDist, nextNode});
			}
		}
	}
}