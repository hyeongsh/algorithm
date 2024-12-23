
#include <iostream>

int main(void) {
	std::string str;
	std::cin >> str;
	for (int i = 1; i < str.size(); i++) {
		std::string first = str.substr(0, i);
		std::string second = str.substr(i, str.size());
		int firstNum = 1;
		int secondNum = 1;
		for (int j = 0; j < first.size(); j++) {
			firstNum *= first[j] - '0';
		}
		for (int j = 0; j < second.size(); j++) {
			secondNum *= second[j] - '0';
		}
		if (firstNum == secondNum) {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;
}