/*
25195번
Yes or yes
골드 4

문제
지정해준 노드를 거치지 않은 상태로 더이상 나아갈 수 없는 위치까지 도달할 수 있으면 Yes, 없으면 yes
*/

#include <iostream>
#include <vector>
#include <queue>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> vec(n + 1);
	while (m--) {
		int start, end;
		std::cin >> start >> end;
		vec[start].push_back(end);
	}
	int s;
	std::cin >> s;
	std::vector<int> vis(n + 1);
	while (s--) {
		int trap;
		std::cin >> trap;
		vis[trap] = 1;
	}
	std::queue<int> que;
	que.push(1);
	if (vis[1]) {
		std::cout << "Yes" << std::endl;
		return 0;
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (vec[cur].empty()) {
			std::cout << "yes" << std::endl;
			return 0;
		}
		for (const auto &next : vec[cur]) {
			if (!vis[next]) {
				vis[next] = 1;
				que.push(next);
			}
		}
	}
	std::cout << "Yes" << std::endl;
}