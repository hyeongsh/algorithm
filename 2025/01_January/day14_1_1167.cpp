/*
1167번
트리의 지름
골드 2

문제
트리의 임의의 두 점 사이의 거리 중 가장 긴 것을 찾아라.

입력
1. 정점의 개수 V
2. V개의 간선 정보
3. 정점 a는 정점 b와 거리가 db인 간선, c와는 거리가 dc인 간선으로 연결되어 있음 -> 마지막은 -1
*/

#include <iostream>
#include <vector>
#include <queue>

void bfs(int n, std::vector<std::vector<std::pair<int, int>>> &vec, int start, std::pair<int, int> &max);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int v;
	std::cin >> v;
	std::vector<std::vector<std::pair<int, int>>> vec(v + 1);
	for (int i = 0; i < v; i++) {
		int cur;
		std::cin >> cur;
		while (true) {
			int next, dist;
			std::cin >> next;
			if (next == -1) {
				break ;
			}
			std::cin >> dist;
			vec[cur].push_back({next, dist});
		}
	}
	std::pair<int, int> firstMax = {0, 0};
	bfs(v, vec, 1, firstMax);
	std::pair<int, int> secondMax = {0, 0};
	bfs(v, vec, firstMax.first, secondMax);
	std::cout << secondMax.second << std::endl;
}

void bfs(int n, std::vector<std::vector<std::pair<int, int>>> &vec, int start, std::pair<int, int> &max) {
	std::queue<std::pair<int, int>> que;
	std::vector<int> vis(n + 1);
	que.push({start, 0});
	vis[start] = 1;
	while (!que.empty()) {
		int cur = que.front().first;
		int curCost = que.front().second;
		que.pop();
		int len = vec[cur].size();
		for (const auto &curPath : vec[cur]) {
			int next = curPath.first;
			int nextCost = curPath.second;
			if (!vis[next]) {
				que.push({next, curCost + nextCost});
				vis[next] = 1;
				if (curCost + nextCost > max.second) {
					max = {next, curCost + nextCost};
				}
			}
		}
	}
}