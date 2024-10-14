
#include <iostream>
#include <stack>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string paran;
		std::stack<char> s;
		std::cin >> paran;
		for (int i = 0; i < paran.size(); i++) {
			if (paran[i] == '(') {
				s.push('(');
			} else if (paran[i] == ')' && !s.empty()) {
				s.pop();
			} else {
				s.push(')');
				break ;
			}
		}
		if (s.empty()) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
}