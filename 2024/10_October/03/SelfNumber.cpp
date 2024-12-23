
#include <iostream>

int arr[10001] = {0, };

void selfNum(int num) {
	if (arr[num] == 0) {
		std::cout << num << std::endl;
	}
	int ans = num;
	ans += num / 10000;
	num %= 10000;
	ans += num / 1000;
	num %= 1000;
	ans += num / 100;
	num %= 100;
	ans += num / 10;
	num %= 10;
	ans += num;
	if (ans <= 10000) {
		arr[ans] = 1;
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	for (int i = 1; i < 10001; i++) {
		selfNum(i);
	}
}