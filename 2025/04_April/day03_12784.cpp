/*
제목: 인하니카 공화국
번호: 12784번
난이도: 골드 3

문제
1번 노드부터 어떻게 가든 리프 노드로 갈 수 없게 만들어야 함.

*/

// 라이브러리 설정
#include <iostream>
#include <climits>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int T;
int N, M;

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

int checkRoute(std::vector<std::vector<std::pair<int, int>>> &map, std::vector<bool> &vis, int cur, int dist);

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
	std::cin >> T;
}

void setting() {
	for (int t = 0; t < T; t++) {
		std::cin >> N >> M;
		std::vector<std::vector<std::pair<int, int>>> map(N + 1);
		std::vector<bool> vis(N + 1, false);
		for (int m = 0; m < M; m++) {
			int a1, a2, d;
			std::cin >> a1 >> a2 >> d;
			map[a1].push_back({a2, d});
			map[a2].push_back({a1, d});
		}
		vis[1] = true;
		std::cout << checkRoute(map, vis, 1, INT_MAX) << std::endl;
	}
}

void findAnswer() {

}

int checkRoute(std::vector<std::vector<std::pair<int, int>>> &map, std::vector<bool> &vis, int cur, int dist) {
	int size = map[cur].size();
	if (size == 1 && cur != 1) {
		return map[cur][0].second;
	}
	int childrenDist = 0;
	for (int i = 0; i < size; i++) {
		int nextNode = map[cur][i].first;
		int nextDist = map[cur][i].second;
		if (!vis[nextNode]) {
			vis[nextNode] = true;
			int childDist = checkRoute(map, vis, nextNode, nextDist);
			childrenDist += childDist;
		}
	}
	if (childrenDist < dist) {
		dist = childrenDist;
	}
	return dist;
}