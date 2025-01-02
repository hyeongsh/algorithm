/*
15663번 실버2

N개의 자연수 중 M개를 골라 수열을 만들기
*/

#include <iostream>
#include <vector>
#include <algorithm>

void permutation(int n, int m, int cur, std::vector<int> &vec, std::vector<int> &arr);

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr(n);
	std::vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	permutation(n, m, 0, vec, arr);
}

void permutation(int n, int m, int cur, std::vector<int> &vec, std::vector<int> &arr) {
	int len;
	if (cur >= m) {
		for (int i = 0; i < m; i++) {
			std::cout << vec[i];
			if (i == m - 1) {
				std::cout << "\n";
			} else {
				std::cout << " ";
			}
		}
		return ;
	}
	len = arr.size();
	for (int i = 0; i < len; i++) {
		if (i != 0 && arr[i] == arr[i - 1]) {
			continue ;
		}
		vec[cur] = arr[i];
		std::vector<int> newArr = arr;
		newArr.erase(newArr.begin() + i);
		permutation(n, m, cur + 1, vec, newArr);
	}
}