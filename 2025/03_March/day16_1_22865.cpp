/*
가장 먼 곳
22865번
골드 4

문제
A, B, C가 있는 곳에서 가장 먼 곳을 찾는 문제
가장 짧은 거리가 긴 것을 선택해야 한다.
*/

#include <iostream>
#include <vector>
#include <queue>

int n; // 땅 후보 개수
int a, b, c; // 친구들의 위치 
int m; // 도로의 개수

std::vector<std::vector<std::pair<int, int>>> map(100001);
std::vector<int> res(100001, 2147483647);
std::pair<int, int> maxNode = {1, -1};

void dijkstra(int start);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	std::cin >> a >> b >> c;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int d, e, l;
		std::cin >> d >> e >> l;
		map[d].push_back({l, e});
		map[e].push_back({l, d});
	}
	
	dijkstra(a);
	dijkstra(b);
	dijkstra(c);
	for (int i = 1; i <= n; i++) {
		if (maxNode.second < res[i]) {
			maxNode = {i, res[i]};
		}
	}
	std::cout << maxNode.first << std::endl;
}

void dijkstra(int start) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::vector<int> midRes(100001, 2147483647);
	midRes[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int curL = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (midRes[curNode] < curL) {
			continue ;
		}
		int size = map[curNode].size();
		for (int i = 0; i < size; i++) {
			int nextL = map[curNode][i].first;
			int nextNode = map[curNode][i].second;
			if (midRes[nextNode] > curL + nextL) {
				midRes[nextNode] = curL + nextL;
				pq.push({midRes[nextNode], nextNode});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] > midRes[i]) {
			res[i] = midRes[i];
		}
	}
}