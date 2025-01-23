/*
27211번
도넛 행성
골드 5

문제
N * M 칸의 도넛 모양
오른쪽으로 M칸 이동할 시 원래 위치로 돌아올 것임.
왼쪽으로 한 칸 이동할 시 M - 1칸에 위치할 것임.
움직일 수 있는 구역을 나눠서 몇 개인지 출력
*/

#include <iostream>
#include <queue>

int myMap[1001][1001];
int vis[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::queue<std::pair<int, int>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> myMap[i][j];
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (myMap[i][j] == 0 && vis[i][j] == 0) {
				que.push({i, j});
				vis[i][j] = ++max;
			}
			while (!que.empty()) {
				int curX = que.front().first;
				int curY = que.front().second;
				que.pop();
				for (int k = 0; k < 4; k++) {
					int nextX = (n + curX + dir[k][0]) % n;
					int nextY = (m + curY + dir[k][1]) % m;
					if (myMap[nextX][nextY] == 0 && vis[nextX][nextY] == 0) {
						que.push({nextX, nextY});
						vis[nextX][nextY] = max;
					}
				}
			}
		}
	}
	std::cout << max << std::endl;
}