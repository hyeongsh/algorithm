
#include <iostream>
#include <vector>
#include <queue>

int map[101];

int main(void) {
	int n;
	int k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> vec(n + 1);

	for (int i = 0; i < k; i++) {
		int a, b;
		std::cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	int birus = 0;
	std::queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		
		if (map[cur] == 0) {
			map[cur] = 1;
			birus++;
		} else {
			continue ;
		}
		for (int i = 0; i < vec[cur].size(); i++) {
			if (map[vec[cur][i]] == 0) {
				que.push(vec[cur][i]);
			}
		}
	}
	std::cout << birus - 1 << std::endl;
}