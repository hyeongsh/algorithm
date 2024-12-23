
#include <iostream>
#include <queue>

char colorMap[101][101] = {0, };
char blindMap[101][101] = {0, };
int vis[101][101] = {0, };
int bvis[101][101] = {0, };
int aMove[4] = {1, -1, 0, 0};
int bMove[4] = {0, 0, 1, -1};
std::queue< std::pair< int, int > > que;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> colorMap[i][j];
			if (colorMap[i][j] == 'G') {
				blindMap[i][j] = 'R';
			} else {
				blindMap[i][j] = colorMap[i][j];
			}
		}
	}
	int max = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				que.push(std::make_pair(i, j));
				vis[i][j] = max++;
			}
			while (!que.empty()) {
				int curA = que.front().first;
				int curB = que.front().second;
				que.pop();
				for (int i = 0; i < 4; i++) {
					int nextA = curA + aMove[i];
					int nextB = curB + bMove[i];
					if (nextA < 0 || nextA >= n || nextB < 0 || nextB >= n) {
						continue ;
					} else if (vis[nextA][nextB]) {
						continue ;
					} else if (colorMap[curA][curB] == colorMap[nextA][nextB]) {
						vis[nextA][nextB] = vis[curA][curB];
						que.push(std::make_pair(nextA, nextB));
						if (vis[nextA][nextB] > max) {
							max = vis[nextA][nextB];
						}
					}
				}
			}
		}
	}
	int bmax = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bvis[i][j] == 0) {
				que.push(std::make_pair(i, j));
				bvis[i][j] = bmax++;
			}
			while (!que.empty()) {
				int curA = que.front().first;
				int curB = que.front().second;
				que.pop();
				for (int i = 0; i < 4; i++) {
					int nextA = curA + aMove[i];
					int nextB = curB + bMove[i];
					if (nextA < 0 || nextA >= n || nextB < 0 || nextB >= n) {
						continue ;
					} else if (bvis[nextA][nextB]) {
						continue ;
					} else if (blindMap[curA][curB] == blindMap[nextA][nextB]) {
						bvis[nextA][nextB] = bvis[curA][curB];
						que.push(std::make_pair(nextA, nextB));
						if (bvis[nextA][nextB] > bmax) {
							bmax = bvis[nextA][nextB];
						}
					}
				}
			}
		}
	}
	std::cout << max - 1 << " " << bmax - 1 << std::endl;
}