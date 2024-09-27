
#include <iostream>
#include <algorithm>
#include <vector>

int min = 2147483647;
int visit[6] = {0, };
int map[51][51];
int N, M, K;

void dfs(int k, std::vector<int> r, std::vector<int> c, std::vector<int> s);
void spin(int r, int c, int s);
void back_spin(int r, int c, int s);
void printmap();

int main(void) {
	std::cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> map[i][j];
		}
	}
	std::vector<int> r(K);
	std::vector<int> c(K);
	std::vector<int> s(K);
	for (int i = 0; i < K; i++) {
		std::cin >> r[i] >> c[i] >> s[i];
	}
	dfs(K, r, c, s);
	std::cout << min << std::endl;
}

void dfs(int k, std::vector<int> r, std::vector<int> c, std::vector<int> s) {
	if (k == 0) {
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += map[i][j];
			}
			if (min > sum) {
				min = sum;
			}
		}
		return ;
	}
	for (int i = 0; i < K; i++) {
		if (visit[i]) {
			continue ;
		}
		visit[i] = 1;
		spin(r[i], c[i], s[i]);
		dfs(k - 1, r, c, s);
		back_spin(r[i], c[i], s[i]);
		visit[i] = 0;
	}
}

void spin(int r, int c, int s) {
	while (s > 0) {
		int left_top_a = r - s;
		int left_top_b = c - s;
		int right_bot_a = r + s;
		int right_bot_b = c + s;
		int tmp;
		tmp = map[left_top_a][right_bot_b];
		for (int i = right_bot_b; i > left_top_b; i--) {
			map[left_top_a][i] = map[left_top_a][i - 1];
		}
		for (int i = left_top_a; i < right_bot_a; i++) {
			map[i][left_top_b] = map[i + 1][left_top_b];
		}
		for (int i = left_top_b; i < right_bot_b; i++) {
			map[right_bot_a][i] = map[right_bot_a][i + 1];
		}
		for (int i = right_bot_a; i > left_top_a; i--) {
			map[i][right_bot_b] = map[i - 1][right_bot_b];
		}
		map[left_top_a + 1][right_bot_b] = tmp;
		s--;
	}
}

void back_spin(int r, int c, int s) {
	while (s > 0) {
		int left_top_a = r - s;
		int left_top_b = c - s;
		int right_bot_a = r + s;
		int right_bot_b = c + s;
		int tmp;
		tmp = map[left_top_a][right_bot_b];
		for (int i = left_top_a; i < right_bot_a; i++) {
			map[i][right_bot_b] = map[i + 1][right_bot_b];
		}
		for (int i = right_bot_b; i > left_top_b; i--) {
			map[right_bot_a][i] = map[right_bot_a][i - 1];
		}
		for (int i = right_bot_a; i > left_top_a; i--) {
			map[i][left_top_b] = map[i - 1][left_top_b];
		}
		for (int i = left_top_b; i < right_bot_b; i++) {
			map[left_top_a][i] = map[left_top_a][i + 1];
		}
		map[left_top_a][right_bot_b - 1] = tmp;
		s--;
	}
}

void printmap() {
	std::cout << "====================" << std::endl;
	for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				std::cout << map[i][j] << " ";
			}
			std::cout << std::endl;
		}
	std::cout << "====================" << std::endl;
}