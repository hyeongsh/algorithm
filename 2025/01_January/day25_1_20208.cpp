/*
20208번
진우의 민트초코우유
골드 5

문제
M의 체력을 가지고 이동할 때마다 체력이 1씩 줄어듬.
상 하 좌 우 로만 이동할 수 있으며, 민트초코를 마시면 H만큼 체력 증가.
체력이 0이 되는 순간 이동할 수 없다.
집까지 돌아가는 것까지 고려해서 체력을 사용해야 한다.
최대 몇개의 민트초코우유를 마실 수 있는가
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

std::vector<std::pair<int, int>> v;
std::pair<int, int> start;
int n, m, h, ans;
bool visited[12];

int dist(std::pair<int, int> &a, std::pair<int, int> &b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(std::pair<int, int> cur, int die, int eat) {
	if (die >= dist(cur, start)) {
		ans = std::max(ans, eat);
	}
	for (size_t i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			if (die - dist(cur, v[i]) >= 0) {
				solve(v[i], die - dist(cur, v[i]) + h, eat + 1);
			}
			visited[i] = false;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int inp;
			std::cin >> inp;
			if (inp == 1) {
				start = {i, j};
			} else if (inp == 2) {
				v.push_back({i, j});
			}
		}
	}
	solve(start, m, 0);
	std::cout << ans << std::endl;
}