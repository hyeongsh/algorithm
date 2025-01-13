/*
1865번
웜홀
골드 3

문제
N개의 지점, M개의 도로, W개의 웜홀
도로는 방향이 없고, 웜홀은 방향이 있다
웜홀은 시간이 뒤로 간다
출발할 때보다 도착했을 때 시간이 되돌아간 경우가 있는지 체크

입력과 출력
1. 테스트케이스 개수
2. 지점 수, 도로 수, 웜홀 수,
3. 도로 지점1, 도로 지점2, 시간
4. 웜홀 시작, 웜홀 도착, 줄어드는 시간
*/

#include <iostream>
#include <vector>
#include <climits>


struct Edge {
	int from, to, weight;
};

bool bellmanFord(int n, std::vector<Edge> &edges);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int tc;
	std::cin >> tc;
	while (tc--) {
		int n, m, w;
		std::cin >> n >> m >> w;
		std::vector<Edge> edges;
		for (int i = 0; i < m; i++) {
			int s, e, t;
			std::cin >> s >> e >> t;
			edges.push_back({s, e, t});
			edges.push_back({e, s, t});
		}

		for (int i = 0; i < w; i++) {
			int s, e, t;
			std::cin >> s >> e >> t;
			edges.push_back({s, e, -t});
		}

		if (bellmanFord(n, edges)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}

bool bellmanFord(int n, std::vector<Edge> &edges) {
	std::vector<int> dist(n + 1, INT_MAX);
	std::vector<int> vis(n + 1);
	for (int a = 1; a <= n; a++) {
		if (vis[a]) {
			continue ;
		}
		dist[a] = 0;
		vis[a] = 1;
		for (int i = 1; i < n; i++) {
			for (const auto &edge : edges) {
				if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
					dist[edge.to] = dist[edge.from] + edge.weight;
					vis[edge.to] = 1;
				}
			}
		}

		for (const auto &edge : edges) {
			if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to]) {
				return true;
			}
		}
	}
	return false;
}