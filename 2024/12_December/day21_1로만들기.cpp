
#include <iostream>

int arr[1000001];

int main(void) {
	int n;
	std::cin >> n;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
			arr[i] = arr[i / 2] + 1;
		}
		if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
			arr[i] = arr[i / 3] + 1;
		}
	}
	std::cout << arr[n] << std::endl;
}

// 1000000