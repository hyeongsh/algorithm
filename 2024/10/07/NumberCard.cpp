
#include <iostream>
#include <algorithm>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	std::cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::sort(arr, arr + n);
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int input;
		std::cin >> input;
		std::cout << std::binary_search(arr, arr + n, input) << " ";
	}
	std::cout << std::endl;
}