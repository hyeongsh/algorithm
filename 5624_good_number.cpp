
#include <iostream>

int N;
int arr[5001] = {0, };
int number[600001] = {0, };


int main(void) {
	std::cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if (number[arr[i] - arr[j] + 300000]) {
				ans += 1;
				break ;
			}
		}
		for (int j = 0; j <= i; j++) {
			int sum_two = arr[i] + arr[j];
			number[sum_two + 300000] = 1;
		}
	}
	std::cout << ans << std::endl;
}
