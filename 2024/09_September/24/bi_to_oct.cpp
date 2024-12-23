
#include <iostream>
#include <string>

int main(void) {
	std::string binaryNum;
	std::string octalNum;
	std::cin >> binaryNum;

	while (binaryNum.size() % 3 != 0) {
		binaryNum = "0" + binaryNum;
	}
	for (int i = 0; i < binaryNum.size(); i += 3) {
		octalNum += (binaryNum[i] - '0') * 4 + (binaryNum[i + 1] - '0') * 2 + (binaryNum[i + 2] - '0') + '0';
	}
	std::cout << octalNum << std::endl;
}
