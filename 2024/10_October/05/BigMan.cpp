
#include <iostream>
#include <vector>

int main(void) {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> arr(n);
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
				ans[i]++;
			}
		}
		ans[i]++;
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " ";
	}
}