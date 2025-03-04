/*
알고스팟
1261번
골드 4

문제
n * m 크기의 미로가 빈 방이나 벽으로 이루어져 있음.
벽은 부수지 않으면 이동 불가

1,1 -> n,m 으로 이동하는 동안 최소 몇 개의 벽을 부숴야 하는지 구해야 함
*/

#include <iostream>
#include <queue>

int map[101][101];
int vis[101][101];

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(void) {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		std::string line;
		std::cin >> line;
		for (int j = 1; j <= n; j++) {
			map[i][j] = line[j - 1] - '0';
		}
	}
	std::queue<std::pair<int, int>> que;
	vis[1][1] = 1;
	que.push({1, 1});
	while (!que.empty()) {
		int curA = que.front().first;
		int curB = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nextA = curA + dir[i][0];
			int nextB = curB + dir[i][1];
			if (nextA < 1 || nextA > m || nextB < 1 || nextB > n) {
				continue ;
			}
			int nextW = 0;
			if (map[nextA][nextB] == 1) {
				nextW = 1;
			}
			if (vis[nextA][nextB] == 0) {
				vis[nextA][nextB] = vis[curA][curB] + nextW;
				que.push({nextA, nextB});
			} else if (vis[nextA][nextB] > vis[curA][curB] + nextW) {
				vis[nextA][nextB] = vis[curA][curB] + nextW;
				que.push({nextA, nextB});
			}
		}
	}
	std::cout << vis[m][n] - 1 << std::endl;
}