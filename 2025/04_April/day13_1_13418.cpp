/*
제목: 학교 탐방하기
번호: 13418번
난이도: 골드 3

문제
최소한의 경로만을 탐색할 때 최대비용과 최소비용의 차이를 구해야 하는 문제

*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 1001

// 전역 변수 선언
int N, M;
std::vector<std::pair<std::pair<int, int>, int>> graph(MAX);
int minUnion[MAX];
int maxUnion[MAX];

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
	std::cin >> N >> M;
	for (int i = 0; i <= M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graph.push_back({{a, b}, c});
	}	
}

void findAnswer() {
	for (int i = 0; i < MAX; i++) {
		minUnion[i] = i;
		maxUnion[i] = i;
	}
	for (const auto &road : graph) {
		int a = road.first.first;
		int b = road.first.second;
		int c = road.second;
		if (c == 1) {
			unionGroup(a, b, minUnion);
		} else {
			unionGroup(a, b, maxUnion);
		}
	}
	int minRes = countGroups(minUnion);
	int maxRes = countGroups(maxUnion);
	minRes = (minRes - 1) * (minRes - 1);
	maxRes = (N + 1 - maxRes) * (N + 1 - maxRes);
	std::cout << maxRes - minRes << std::endl;
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