/*
11724번

연결 요소의 개수 구하기
방향 없는 그래프가 주어질 때 연결된 노드묶음이 몇 개인지 체크
n, m이 주어지고, m개의 연결노드가 주어진다.

1 - 2, 5
2 - 1, 3, 4, 5
3 - 2, 4
4 - 2, 3, 5, 6
5 - 1, 2, 4
6 - 

*/

#include <iostream>
#include <vector>
#include <queue>

int vis[1001];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	int max = 0;
	std::cin >> n >> m;
	std::vector<std::vector<int>> vec(n + 1);
	std::queue<int> que;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int cur;
		if (vis[i] == 0) {
			que.push(i);
			cur = ++max;
			vis[i] = cur;
		}
		while (!que.empty()) {
			int x = que.front();
			que.pop();
			for (int j = 0; j < vec[x].size(); j++) {
				if (vis[vec[x][j]] == 0) {
					vis[vec[x][j]] = cur;
					que.push(vec[x][j]);
				}
			}
		}
	}
	std::cout << max << std::endl;
}