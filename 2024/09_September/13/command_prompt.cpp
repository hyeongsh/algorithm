
#include <iostream>

int main(void) {
	int N;
	std::string ans;
	std::string str;
	std::cin >> N;
	std::cin >> ans;
	for (int i = 1; i < N; i++) {
		std::cin >> str;
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] != str[j]) {
				ans[j] = '?';
			}
		}
	}
	std::cout << ans << std::endl;
}