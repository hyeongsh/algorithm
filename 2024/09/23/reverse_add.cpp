
#include <iostream>
#include <algorithm>
#include <string>

int main(void) {
	std::string x, y;
	std::cin >> x >> y;
	std::reverse(x.begin(), x.end());
	std::reverse(y.begin(), y.end());
	int num = std::stoi(x) + std::stoi(y);
	std::string ans = std::to_string(num);
	std::reverse(ans.begin(), ans.end());
	std::cout << std::stoi(ans) << std::endl;
}