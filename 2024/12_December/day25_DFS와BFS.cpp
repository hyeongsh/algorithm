/*
1260번 실버2

그래프를 DFS와 BFS로 탐색하여 방문한 점들을 순서대로 출력

*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

std::vector<int> bfsVec;
int bfsVis[1001];
std::vector<int> dfsVec;
int dfsVis[1001];

void bfs(std::vector<std::set<int>> &vec, int i);
void dfs(std::vector<std::set<int>> &vec, int i);

int main(void) {
	int n, m, i;
	std::cin >> n >> m >> i;
	std::vector<std::set<int>> vec(n + 1);
	for (int j = 0; j < m; j++) {
		int a, b;
		std::cin >> a >> b;
		vec[a].insert(b);
		vec[b].insert(a);
	}
	bfs(vec, i);
	dfs(vec, i);
	for (int j = 0; j < dfsVec.size(); j++) {
		std::cout << dfsVec[j] << " ";
	}
	std::cout << "\n";
	for (int j = 0; j < bfsVec.size(); j++) {
		std::cout << bfsVec[j] << " ";
	}
	std::cout << "\n";
}

void bfs(std::vector<std::set<int>> &vec, int i) {
	//bfs
	std::queue<int> que;
	que.push(i);
	bfsVis[i] = 1;
	bfsVec.push_back(i);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto it = vec[x].begin(); it != vec[x].end(); it++) {
			if (bfsVis[*it] == 0) {
				que.push(*it);
				bfsVis[*it] = 1;
				bfsVec.push_back(*it);
			}
		}
	}
}

void dfs(std::vector<std::set<int>> &vec, int i) {
	dfsVis[i] = 1;
	dfsVec.push_back(i);
	for (auto it = vec[i].begin(); it != vec[i].end(); it++) {
		if (dfsVis[*it] == 0) {
			dfs(vec, *it);
		}
	}
}
