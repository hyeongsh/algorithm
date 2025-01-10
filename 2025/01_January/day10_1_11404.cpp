/*
11404번
플로이드
골드 4

문제
n개의 도시, 그 사이를 잇는 m개의 버스
버스마다 비용이 다를 때 a에서 b도시로 가는 비용의 최솟값 구하기

입력과 출력
n, m 이후로 출발 도시, 도착 도시, 비용으로 이루어진 버스 정보
시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있음

i번째 줄에 i번째 도시에서 j번째 도시로 가는 최소 비용을 전부 나열
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void dijkstra(int n, std::vector<std::vector<std::pair<int, int>>> &vec,
std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>> &que);

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> vec(n + 1);
	for (int i = 0; i < m; i++) {
		int st, en, w;
		std::cin >> st >> en >> w;
		vec[st].push_back({w, en});
	}
	std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>> que;
	for (int i = 1; i <= n; i++) {
		que.push({0, i});
		dijkstra(n, vec, que);
	}
}

void dijkstra(int n, std::vector<std::vector<std::pair<int, int>>> &vec,
std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>> &que) {
	std::vector<long long> ans(n + 1, INT_MAX);
	ans[que.top().second] = 0;
	while (!que.empty()) {
		int curWeight = que.top().first;
		int curCity = que.top().second;
		que.pop();
		int len = vec[curCity].size();
		for (int i = 0; i < len; i++) {
			int nextWeight = vec[curCity][i].first;
			int nextCity = vec[curCity][i].second;
			if (ans[nextCity] > curWeight + nextWeight) {
				ans[nextCity] = curWeight + nextWeight;
				que.push({ans[nextCity], nextCity});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX) {
			ans[i] = 0;	
		}
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}