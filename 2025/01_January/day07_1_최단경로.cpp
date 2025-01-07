/*
1753번 최단경로 골드4

그래프, 경로마다 가중치 존재
다익스트라 알고리즘을 사용하여 계산
시작점은 테스트마다 주어짐
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main(void) {
	int v, e;
	int start;
	std::cin >> v >> e >> start;
	std::vector<std::vector<std::pair<int, int>>> vec(v + 1);
	std::vector<int> vis(v + 1, INT_MAX);
	for (int i = 0; i < e; i++) {
		int v1, v2, w;
		std::cin >> v1 >> v2 >> w;
		vec[v1].push_back({w, v2});
	}
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
	que.push({0, start});
	vis[start] = 0;
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();
		if (vis[cur] < cost) {
			continue ;
		}
		int len = vec[cur].size();
		for (int i = 0; i < len; i++) {
			int nextCost = vec[cur][i].first;
			int next = vec[cur][i].second;
			if (cost + nextCost < vis[next]) {
				vis[next] = cost + nextCost;
				que.push({vis[next], next});
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (vis[i] == INT_MAX) {
			std::cout << "INF" << "\n";
		} else {
			std::cout << vis[i] << "\n";
		}
	}
	// 입력 테스트
	// for (int i = 1; i <= v; i++) {
	// 	int len = vec[i].size();
	// 	std::cout << i << " = ";
	// 	for (int j = 0; j < len; j++) {
	// 		std::cout << "{" << vec[i][j].first << ", " << vec[i][j].second << "} ";
	// 	}
	// 	std::cout << std::endl;
	// }
}