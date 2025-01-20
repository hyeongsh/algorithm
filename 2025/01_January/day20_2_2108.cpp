/*
2108번
통계학
실버 3

문제
산술평균, 중앙값, 최빈값, 범위를 출력
최빈값은 여러개 있을 경우, 두번째로 작은 값을 출력한다.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int arr[8001];
std::vector<int> vec;

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		sum += num;
		arr[num + 4000] += 1;
		if (max < arr[num + 4000]) {
			max = arr[num + 4000];
		}
		vec.push_back(num);
	}
	double ans = std::round((double)sum / n);
	if (ans == 0.0) {
		ans = 0.0;
	}
	std::cout << ans << std::endl;
	std::sort(vec.begin(), vec.end());
	std::cout << vec[n / 2] << std::endl;
	int flag = 0;
	int res;
	for (int i = 0; i < 8001; i++) {
		if (arr[i] == max) {
			flag++;
			if (flag == 1 || flag == 2) {
				res = i - 4000;
			}
		}
	}
	std::cout << res << std::endl;
	std::cout << vec[vec.size() - 1] - vec[0] << std::endl;
}