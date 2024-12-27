/*
15654번 실버3

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 됨
오름차순 -> 같은 수는 같은 곳에

*/

#include <iostream>
#include <vector>
#include <algorithm>

void permutation(int n, int m, int cur, std::vector<int> &vec, std::vector<int> &arr);

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vec(m + 1);
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	permutation(n, m, 1, vec, arr);
}

void permutation(int n, int m, int cur, std::vector<int> &vec, std::vector<int> &arr) {
	if (cur > m) {
		for (int i = 1; i < vec.size(); i++) {
			std::cout << vec[i];
			if (i == vec.size() - 1) {
				std::cout << "\n";
			} else {
				std::cout << " ";
			}
		}
		return ;
	}
	for (int i = 0; i < arr.size(); i++) {
		vec[cur] = arr[i];
		std::vector<int> newArr = arr;
		newArr.erase(newArr.begin() + i);
		permutation(n, m, cur + 1, vec, newArr);
	}
}