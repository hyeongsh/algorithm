
#include <iostream>
#include <queue>

int map[100][100];
int vis[100][100];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(void) {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	std::queue<std::pair<int, int>> q;
	q.push({0, 0});
	vis[0][0] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newA = a + dir[i][0];
			int newB = b + dir[i][1];
			if (newA < 0 || newA == n || newB < 0 || newB == m) {
				continue ;
			} else if (map[newA][newB] == 0 || vis[newA][newB] == 1) {
				continue ;
			} else {
				vis[newA][newB] = 1;
				map[newA][newB] = map[a][b] + 1;
				q.push({newA, newB});
			}
		}
	}
	std::cout << map[n - 1][m - 1] << std::endl;
}