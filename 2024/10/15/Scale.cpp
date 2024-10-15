
#include <iostream>

int main(void) {
	int prev;
	int flag = 0;
	std::string ans[4] = {"x", "ascending", "descending", "mixed"};
	std::cin >> prev;
	for (int i = 1; i < 8; i++) {
		int cur;
		std::cin >> cur;
		if (prev < cur && flag == 2) {
			flag = 3;
		} else if (prev > cur && flag == 1) {
			flag = 3;
		} else if (prev < cur && flag != 3) {
			flag = 1;
		} else if (prev > cur && flag != 3) {
			flag = 2;
		}
		prev = cur;
	}
	std::cout << ans[flag] << std::endl;
}