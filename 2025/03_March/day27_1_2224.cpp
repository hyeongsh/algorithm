/*
제목: 명제 증명
번호: 2224번
난이도: 골드 4

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100

// input 변수 선언
int n;
std::vector<std::vector<int>> vec(MAX);
std::vector<std::vector<int>> res(MAX);

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
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		std::string op;
		std::cin >> a >> op >> b;
		vec[a - 'A'].push_back(b - 'A');
	}
}

void setting() {
	for (int i = 0; i < MAX; i++) {
		std::queue<int> que;
		std::vector<bool> vis(MAX, false);
		if (vec[i].size()) {
			que.push(i);
		}
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			for (int j = 0; j < vec[x].size(); j++) {
				int nextX = vec[x][j];
				if (i != nextX && !vis[nextX]) {
					vis[nextX] = true;
					res[i].push_back(nextX);
					que.push(nextX);
				}
			}
		}
	}
}

void findAnswer() {
	int ansSize = 0;
	for (int i = 0; i < MAX; i++) {
		ansSize += res[i].size();
	}
	std::cout << ansSize << std::endl;
	for (int i = 0; i < MAX; i++) {
		if (!res[i].empty()) {
			std::sort(res[i].begin(), res[i].end());
			for (int j = 0; j < res[i].size(); j++) {
				std::cout << char(i + 'A') << " => " << char(res[i][j] + 'A') << "\n";
			}
		}
	}
}