/*
제목: 불우이웃돕기
번호: 1414번
난이도: 골드 3

문제
N개의 방에 랜선을 제공하여 모두 서로 연결되도록 하고 싶음.

5 + 14 + 
3 선택 1과 2 연결 -> 4 선택 2와 4 연결 -> 5 선택 1과 3 연결 -> 5 선택 2와 4 x -> 14 선택 3과 4
0	20	15	16
3	0	15	4
5	18	0	15
16	5	14	0

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 51

// 전역 변수 선언
int N;
int board[MAX];
int res = 0;
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;
// 기본 함수
void input();
void findAnswer();

int findUnion(int v, int *groups);
void unionGroup(int a, int b, int *groups);
int countGroups(int *groups);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			std::cin >> x;
			if (x == '0') {
				x = 0;
			} else if (x >= 'a') {
				x -= 'a' - 1;
			} else {
				x -= 'A' - 27;
			}
			if (i == j) {
				res += x;
			} else {
				pq.push({x, {i, j}});
			}
		}
	}
}

void findAnswer() {
	for (int i = 0; i < N; i++) {
		board[i] = i;
	}
	while (!pq.empty()) {
		int curA = pq.top().second.first;
		int curB = pq.top().second.second;
		int curDist = pq.top().first;
		pq.pop();
		if (curDist == 0) {
			continue ;
		}
		curA = findUnion(curA, board);
		curB = findUnion(curB, board);
		if (curA != curB) {
			unionGroup(curA, curB, board);
		} else {
			res += curDist;
		}
	}
	if (countGroups(board) == 1) {
		std::cout << res << std::endl;
	} else {
		std::cout << -1 << std::endl;
	}
}

int findUnion(int v, int *groups) {
	while (groups[v] != v) {
		v = groups[v];
	}
	return v;
}

void unionGroup(int a, int b, int *groups) {
	a = findUnion(a, groups);
	b = findUnion(b, groups);
	int small = std::min(a, b);
	int big = std::max(a, b);
	groups[small] = big;
}

int countGroups(int *groups) {
	int count = 0;
	for (int i = 0; i <= N; i++) {
		int cur = i;
		if (groups[cur] == -1) {
			continue ;
		}
		while (groups[cur] != cur && groups[cur] != -1) {
			int next = groups[cur];
			groups[cur] = -1;
			cur = next;
		}
		if (groups[cur] == cur) {
			groups[cur] = -1;
			count++;
		}
	}	
	return count;
}