
#include <iostream>

int arr[21] = {0, };

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string oper;
		int num;
		std::cin >> oper;
		if (oper != "all" && oper != "empty") {
			std::cin >> num;
		}
		if (oper == "add") {
			arr[num] = 1;
		} else if (oper == "remove") {
			arr[num] = 0;
		} else if (oper == "check") {
			std::cout << arr[num] << "\n";
		} else if (oper == "toggle") {
			arr[num] = (arr[num] == 0);
		} else if (oper == "all") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 1;
			}
		} else if (oper == "empty") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 0;
			}
		}
	}
}