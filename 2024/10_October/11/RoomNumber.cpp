
#include <iostream>

int numSet[10] = {0, };

int main(void) {
	std::string number;
	int max = 0;
	std::cin >> number;
	for (int i = 0; i < number.size(); i++) {
		int index = number[i] - '0';
		if (index == 6 && numSet[6] > numSet[9]) {
			index = 9;
		} else if (index == 9 && numSet[9] > numSet[6]) {
			index = 6;
		}
		numSet[index]++;
		if (max < numSet[index]) {
			max = numSet[index];
		}
	}
	std::cout << max << std::endl;
}