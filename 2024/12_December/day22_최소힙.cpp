
#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> que;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		if (num == 0) {
			if (que.empty()) {
				std::cout << 0 << "\n";
			} else {
				std::cout << que.top() << "\n";
				que.pop();
			}
		} else {
			que.push(num);
		}
	}
}