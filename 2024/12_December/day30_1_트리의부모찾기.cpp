/*
11725번 실버2

루트 없는 트리가 주어지고, 트리의 루트는 1
각 노드의 부모를 구하는 프로그램

7
2 4
4 7
3 5
1 6
4 1
6 3

	   1
	6	  4
  3		2	7
5

1 2 3 4 5 6 7
0 4 6 1 3 1 4
*/

#include <iostream>
#include <vector>
#include <queue>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> vec(n + 1);
	std::vector<int> res(n + 1);
	std::vector<int> vis(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	std::queue<int> que;
	que.push(1);
	vis[1] = 1;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		int length = vec[x].size();
		for (int i = 0; i < length; i++) {
			int y = vec[x][i];
			if (vis[y] == 0) {
				vis[y] = 1;
				que.push(y);
				res[y] = x;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		std::cout << res[i] << "\n";
	}
}