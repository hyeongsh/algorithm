
#include <iostream>

int N;
int arr[100001] = {0, };
int exist[100001] = {0, };
int start = 0;
int end = 0;
long long ans = 0;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	while (end < N) {
		if (exist[arr[end]]) {
			while (arr[start] != arr[end]) {
				exist[arr[start++]] = 0;
			}
			start++;
		}
		ans += end - start + 1;
		exist[arr[end++]] = 1;
	}
	std::cout << ans << std::endl;
}