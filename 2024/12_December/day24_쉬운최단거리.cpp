/*
14940번 실버1

지도를 보고 모든 지점을 목표지점까지의 거리로 변경하는 문제
이동은 가로, 세로로만 가능

*/

#include <iostream>
#include <queue>

int map[1001][1001];
int dist[1001][1001];
int vis[1001][1001];

int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	int a, b;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 2) {
				a = i;
				b = j;
			}
		}
	}
	std::queue<std::pair<int, int>> que;
	que.push({a, b});
	vis[a][b] = 1;
	while (!que.empty()) {
		int curA = que.front().first;
		int curB = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextA = curA + direct[i][0];
			int nextB = curB + direct[i][1];
			if (nextA >= 0 && nextA <= 1000 && nextB >= 0 && nextB <= 1000 && !vis[nextA][nextB] && map[nextA][nextB]) {
				dist[nextA][nextB] = dist[curA][curB] + 1;
				vis[nextA][nextB] = 1;
				que.push({nextA, nextB});
			}
		}	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !dist[i][j]) {
				std::cout << -1;
			} else {
				std::cout << dist[i][j];
			}
			if (j == m - 1) {
				std::cout << "\n";
			} else {
				std::cout << " ";
			}
		}
	}
}