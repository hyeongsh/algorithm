
#include <iostream>

int main(void) {
	std::string str;
	while (true) {
		std::cin >> str;
		if (str == "0") {
			break ;
		}
		int st = 0;
		int en = str.size() - 1;
		for (int i = 0; i < str.size() / 2; i++) {
			if (str[st] != str[en]) {
				std::cout << "no" << std::endl;
				break ;
			}
			st++;
			en--;
		}
		if (st >= en) {
			std::cout << "yes" << std::endl;
		}
	}
}