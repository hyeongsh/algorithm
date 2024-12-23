
#include <iostream>

int arr[100001] = {0, };

int main(void) {
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int weight;
		int value;
		std::cin >> weight >> value;
		for (int j = k; j >= weight; j--) {
			arr[j] = std::max(arr[j], arr[j - weight] + value);
		}
		// for (int j = k; j > 0; j--) {
		// 	std::cout << arr[j] << std::endl;
		// }
		// std::cout << "-----------" << std::endl;
	}
	std::cout << arr[k] << std::endl;
}
