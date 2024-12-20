
#include <iostream>
#include <set>
#include <vector>

std::set<std::string> names;
std::set<std::string> res;
std::string name;


int main(void) {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> name;
		names.insert(name);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> name;
		std::set<std::string>::iterator it = names.find(name);
		if (it != names.end()) {
			res.insert(name);
		}
	}
	std::cout << res.size() << std::endl;
	for (auto it = res.begin(); it != res.end(); it++) {
		std::cout << *it << std::endl;
	}
}