/*
1967번 
트리의 지름 
골드4

문제
트리에서 어떤 두 노드를 선택해서 양쪽으로 당긴다는 가정
이걸 지름이라고 할 때, 가장 긴 지름을 구해서 출력하는 프로그램

입력
1. 노드의 개수 n
2. 간선 정보 n-1개
3. 루트 노드는 항상 1
4. 가중치는 100보다 크지 않은 양의 정수
5. 간선 정보는 번호가 작은 것부터 먼저 입력된다.
*/

#include <iostream>
#include <vector>
#include <queue>

void bsq(int n, std::vector<std::vector<std::pair<int, int>>> &vec, int start, std::pair<int, int> &max);

int main(void) {
	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> vec(n + 1);
	for (int i = 1; i < n; i++) {
		int parent;
		int child;
		int weight;
		std::cin >> parent >> child >> weight;
		vec[parent].push_back({child, weight});
		vec[child].push_back({parent, weight});
	}
	std::pair<int, int> firstMax;
	bsq(n, vec, 1, firstMax);
	std::pair<int, int> secondMax;
	bsq(n, vec, firstMax.first, secondMax);
	std::cout << secondMax.second << std::endl;
}

void bsq(int n, std::vector<std::vector<std::pair<int, int>>> &vec, int start, std::pair<int, int> &max) {
	std::queue<std::pair<int, int>> que;
	std::vector<int> vis(n + 1);
	que.push({start, 0});
	vis[start] = 1;
	while (!que.empty()) {
		int cur = que.front().first;
		int curCost = que.front().second;
		que.pop();
		int len = vec[cur].size();
		for (int i = 0; i < len; i++) {
			int next = vec[cur][i].first;
			int nextCost = vec[cur][i].second;
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