
#include <iostream>
#include <string>
#include <algorithm>

int dfs(std::string dest, std::string src);

int main(void) {
	std::string src;
	std::string dest;
	std::cin >> src >> dest;
	std::cout << dfs(dest, src) << std::endl;
}

int dfs(std::string dest, std::string src) {
	if (dest == src) {
		return 1;
	} else if (dest.size() == src.size()) {
		return 0;
	}
	if (dest[dest.size() - 1] == 'A') {
		std::string next = dest;
		next.erase(next.size() - 1);
		if (dfs(next, src)) {
			return 1;
		}
	}
	if (dest[0] == 'B') {
		std::string next = dest;
		std::reverse(next.begin(), next.end());
		next.erase(next.size() - 1);
		if (dfs(next, src)) {
			return 1;
		}
	}
	return 0;
}

// A
// BABA
// 1

// BAAAAABAA
// BAABAAAAAB

// A
// ABBA