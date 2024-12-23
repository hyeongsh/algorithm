
#include <iostream>
#include <queue>

int tree[100001] = {0, };
std::queue<int> que[100001];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	int u, v;
	int index = 1;
	int ans = -1;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		if (tree[u] == 0 && tree[v] == 0) {
			que[index].push(u);
			que[index].push(v);
			tree[u] = index;
			tree[v] = index;
			index++;
		} else if (tree[u] == 0) {
			que[tree[v]].push(u);
			tree[u] = tree[v];
		} else if (tree[v] == 0) {
			que[tree[u]].push(v);
			tree[v] = tree[u];
		} else if (tree[u] != tree[v]) {
			int big = tree[u];
			int small = tree[v];
			if (que[tree[u]].size() < que[tree[v]].size()) {
				big = tree[v];
				small = tree[u];
			}
			while (!que[small].empty()) {
				int change = que[small].front();
				que[small].pop();
				tree[change] = big;
				que[big].push(change);
			}
		} else {
			ans++;
		}
	}
	int total = 0;
	for (int i = index; i > 0; i--) {
		if (!que[i].empty()) {
			ans++;
			total += que[i].size();
		}
	}
	ans += n - total;
	std::cout << ans << std::endl;
}

// union-find