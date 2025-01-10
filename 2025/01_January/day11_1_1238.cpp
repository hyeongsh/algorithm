/*
1238번
파티
골드 3

문제
N개의 숫자로 구분된 마을에 학생 한 명씩
N명의 학생이 x번 마을에 모여서 파티
가는 길은 단방향 도로
가는 것만이 아니라 돌아오는 것도 해야됨
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

void dijkstra(int x, 
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> &que,
std::vector<std::vector<std::pair<int, int>>> &vec,
std::vector<int> &dist
);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m, x;
	std::cin >> n >> m >> x;
	std::vector<std::vector<std::pair<int, int>>> vec(n + 1);
	std::vector<std::vector<std::pair<int, int>>> revVec(n + 1);
	for (int i = 0; i < m; i++) {
		int st, en, t;
		std::cin >> st >> en >> t;
		vec[st].push_back({t, en});
		revVec[en].push_back({t, st});
	}
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> que;
	std::vector<int> toX(n + 1, INT_MAX);
	dijkstra(x, que, revVec, toX);
	std::vector<int> fromX(n + 1, INT_MAX);
	dijkstra(x, que, vec, fromX);
	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		if (fromX[i] != INT_MAX && toX[i] != INT_MAX) {
            maxTime = std::max(maxTime, fromX[i] + toX[i]);
        }
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << toX[i] << " ";
	// }
	// std::cout << std::endl;
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << fromX[i] << " ";
	// }
	// std::cout << std::endl;
	std::cout << maxTime << std::endl;
}

void dijkstra(int x, 
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> &que,
std::vector<std::vector<std::pair<int, int>>> &vec,
std::vector<int> &dist
) {
	que.push({0, x});
	dist[x] = 0;
	while (!que.empty()) {
		int curTime = que.top().first;
		int curPlace = que.top().second;
		que.pop();
		if (dist[curPlace] < curTime) {
			continue ;
		}
		for (const auto &edge : vec[curPlace]) {
			int nextTime = edge.first;
			int nextPlace = edge.second;
			if (dist[nextPlace] > curTime + nextTime) {
				dist[nextPlace] = curTime + nextTime;
				que.push({dist[nextPlace], nextPlace});
			}
		}
	}
}