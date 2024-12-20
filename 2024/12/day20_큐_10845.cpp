
#include <iostream>
#include <queue>

int main(void) {
	int n;
	std::queue<int> que;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string cmd;
		std::cin >> cmd;
		if (cmd == "push") {
			int num;
			std::cin >> num;
			que.push(num);
		} else if (cmd == "size") {
			std::cout << que.size() << std::endl;
		} else if (cmd == "empty") {
			std::cout << que.empty() << std::endl;
		} else {
			if (que.empty()) {
				std::cout << -1 << std::endl;
			} else if (cmd == "pop") {
				int num = que.front();
				que.pop();
				std::cout << num << std::endl;
			} else if (cmd == "front") {
				std::cout << que.front() << std::endl;
			} else if (cmd == "back") {
				std::cout << que.back() << std::endl;
			}

		}
	}
}