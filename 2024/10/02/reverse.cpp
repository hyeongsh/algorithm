
#include <iostream>
#include <sstream>
#include <algorithm>

int main(void) {
	std::string n;
	std::getline(std::cin, n);
	for (int i = 0; i < std::strtod(n.c_str(), nullptr); i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		std::stringstream ss(tmp);
		std::string str;
		while (ss >> tmp) {
			std::reverse(tmp.begin(), tmp.end());
			str.append(tmp + " ");
		}
		std::cout << str << std::endl;
	}
}