
#include <iostream>
#include <queue>

typedef std::pair < std::pair < int, int >, int > Pair;
int h, w, o, f, a_start, b_start, a_end, b_end;
int map[101][101];
int vis[101][101];
int direct[2][4] = {{1, -1, 0, 0}, 
					{0, 0, 1, -1}};

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> h >> w >> o >> f >> a_start >> b_start >> a_end >> b_end;
		for (int z = 0; z < 101; z++) {
			for (int x = 0; x < 101; x++) {
				vis[z][x] = false;
				map[z][x] = 0;
			}
		}
		std::queue< Pair > que;
		for (int j = 0; j < o; j++) {
			int a, b, obs;
			std::cin >> a >> b >> obs;
			map[a][b] = obs;
		}
		std::pair<int, int> pos = std::make_pair(a_start, b_start);
		Pair cur = std::make_pair(pos, f);
		que.push(cur);
		vis[a_start][b_start] = 1;
		int success = 0;
		while (!que.empty()) {
			int a, b, f;
			a = que.front().first.first;
			b = que.front().first.second;
			f = que.front().second;
			que.pop();
			if (a == a_end && b == b_end) {
				success = 1;
				break ;
			}
			if (f == 0) {
				continue ;
			}
			// std::cout << "====================" << std::endl;
			// std::cout << "a : " << a << std::endl;
			// std::cout << "b : " << b << std::endl;
			// std::cout << "f : " << f << std::endl;
			// std::cout << "====================" << std::endl;
			for (int i = 0; i < 4; i++) {
				int a_next, b_next, f_next;
				a_next = a + direct[0][i];
				b_next = b + direct[1][i];
				f_next = f - 1;
				if (a_next < 1 || b_next < 1 || a_next > h || b_next > w) {
					continue ;
				} else if (f < map[a_next][b_next] - map[a][b]) {
					continue ;
				} else if (vis[a_next][b_next]) {
					continue ;
				}
				std::pair<int, int> pos = std::make_pair(a_next, b_next);
				Pair next = std::make_pair(pos, f_next);
				vis[a_next][b_next] = 1;
				que.push(next);
			}
		}
		if (success) {
			std::cout << "잘했어!!" << std::endl;
		} else {
			std::cout << "인성 문제있어??" << std::endl;
		}
	}
}
