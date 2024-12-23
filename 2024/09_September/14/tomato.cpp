
#include <iostream>
#include <queue>

int M;
int N;
int map[1001][1001] = {0, };

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

std::queue< std::pair< int, int > > que;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int total = 0;
	int ans = -1;
	std::cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 1) {
				que.push(std::make_pair(i, j));
			} else if (map[i][j] == 0) {
				total++;
			}
		}
	}
	if (total == 0) {
		ans = 0;
	}
	while (!que.empty() && total) {
		int a = que.front().first;
		int b = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int next_a = a + x[i];
			int next_b = b + y[i];
			if (next_a < 0 || next_b < 0 || next_a >= N || next_b >= M) {
				continue ;
			} else if (map[next_a][next_b] == 0) {
				map[next_a][next_b] = map[a][b] + 1;
				total--;
				if (total == 0) {
					ans = map[a][b];
				}
				que.push(std::make_pair(next_a, next_b));
			}
		}
	}
	std::cout << ans << std::endl;
}