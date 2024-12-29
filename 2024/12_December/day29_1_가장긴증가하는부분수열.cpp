/*
11053번 실버2

수열 A가 있을 때 증가하는 부분 수열 중에 가장 긴 수열을 구하고 그 길이를 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

int arr[1000001];
std::vector<int> lis;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		auto pos = std::lower_bound(lis.begin(), lis.end(), arr[i]);

		if (pos == lis.end()) {
			lis.push_back(arr[i]);
		} else {
			*pos = arr[i];
		}
	}
	int length = lis.size();
	std::cout << length << std::endl;
}