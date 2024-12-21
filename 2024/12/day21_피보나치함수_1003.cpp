
#include <iostream>

std::pair<int, int> arr[41];

int main(void) {

	arr[0] = {1, 0};
	arr[1] = {0, 1};
	for (int i = 2; i < 41; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		std::cout << arr[x].first << " " << arr[x].second << " " << std::endl;
	}
}


// 3 -> 1 : 2, 0 : 1
// 2 -> 1 : 1, 0 : 1
// 1 -> 1 : 1
// 0 -> 0 : 1