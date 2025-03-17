/*
트리의 기둥과 가지
20924번
골드 4

문제
기둥의 길이와 가장 긴 가지의 길이 파악
기둥 : 루트 노드부터 기가 노드(처음으로 자식 노드가 2개 이상인 노드, 리프 노드가 1개인 경우 리프 노드가 기가 노드)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

std::vector<std::vector<std::pair<int, int>>> tree(200001);
std::vector<int> res(200001, INT_MAX);
int gigaNode;
int maxNode;

int n, r; // 노드 개수와 루트 노드 번호

void dijkstra();

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> r;
	for (int i = 1; i < n; i++) {
		int a, b, d;
		std::cin >> a >> b >> d;
		tree[a].push_back({d, b});
		tree[b].push_back({d, a});
	}
	dijkstra();
	std::cout << res[gigaNode] << " " << res[maxNode] - res[gigaNode] << std::endl;
}

void dijkstra() {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({0, r});
	res[r] = 0;
	gigaNode = n;
	maxNode = r;
	while (!pq.empty()) {
		int curD = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (res[curNode] > res[maxNode]) {
			maxNode = curNode;
		}
		if (res[curNode] < curD) {
			continue ;
		}
		for (const auto &node : tree[curNode]) {
			int nextD = node.first;
			int nextNode = node.second;
			if (res[nextNode] > curD + nextD) {
				res[nextNode] = curD + nextD;
				pq.push({res[nextNode], nextNode});
			}
		}
		if (gigaNode == n && tree[curNode].size() > 2) {
			gigaNode = curNode;
		} else if (curNode == r && tree[curNode].size() > 1) {
			gigaNode = curNode;
		}
	}
}