/*
특정한 최단 경로
1504번
골드 4

문제
방향성이 없는 그래프
1번 정점에서 N번 정점으로 이동할 때, 임의로 정해진 두 정점을 무조건 통과해야 하는 조건을 만족해야 함.
최단 경로로 이동하는 프로그램 작성

출력
최단 경로의 길이를 출력한다. 못갈 경우 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<std::pair<int, int>>> graph(801);
int map[4][801];

void makeMap(int cur, int st, int en);

int main(void) {
	for (int i = 0; i < 801; i++) {
		map[0][i] = -1;
		map[1][i] = -1;
		map[2][i] = -1;
		map[3][i] = -1;
	}
	int n, e;
	std::cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		graph[u].push_back({w, v});
		graph[v].push_back({w, u});
	}
	int v1, v2;
	std::cin >> v1 >> v2;	
	makeMap(0, 1, n);
	makeMap(1, v1, v2);
	makeMap(2, v1, n);
	makeMap(3, v2, n);

	int flag1 = 0;
	int flag2 = 0;
	int min1;
	int min2;
	if (map[0][v1] != -1 && map[1][v2] != -1 && map[3][n] != -1)  {
		flag1 = 1;
		min1 = map[0][v1] + map[1][v2] + map[3][n];
	}
	if (map[0][v2] != -1 && map[1][v1] != -1 && map[2][n] != -1) {
		flag2 = 1;
		min2 = map[0][v2] + map[1][v2] + map[2][n];
	}
	if (!flag1 && !flag2) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << std::min(min1, min2) << std::endl;
	}
}

void makeMap(int cur, int st, int en) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	map[cur][st] = 0;
	pq.push({0, st});
	if (st == en) {
		return ;
	}
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		int size = graph[node].size();
		for (int i = 0; i < size; i++) {
			int dWeight = graph[node][i].first;
			int dNode = graph[node][i].second;
			if (map[cur][dNode] == -1 || map[cur][dNode] > weight + dWeight) {
				map[cur][dNode] = weight + dWeight;
				pq.push({map[cur][dNode], dNode});
			}
		}
	}
}