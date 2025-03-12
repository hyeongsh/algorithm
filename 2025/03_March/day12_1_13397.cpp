/*
구간 나누기 2
13397번
골드 4

문제
N개의 수로 이루어진 1차원 배열을 M개 이하의 구간으로 나누어서 구간의 점수의 최댓값을 최소로 한다.
조건1. 하나의 구간은 하나 이상의 연속된 수들로 이루어져 있다.
조건2. 배열의 각 수는 모두 하나의 구간에 포함되어 있어야 한다.
구간의 점수는 구간에 속한 수의 최댓값 - 최솟값이다.

예
1,5,4,6,2,1,3,7 / M=3
1,5 / 4,6,2 / 1,3,7 -> 4, 4, 6 -> 최댓값 6
1,5,4 / 6,2,1 / 3,7 -> 4, 5, 4 -> 최댓값 5
*/

#include <iostream>
#include <vector>

std::vector<int> vec(5001);
int ans = 10001;

void binarySearch(int n, int m);
int checkInterval(int n, int mid);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	binarySearch(n, m);
	std::cout << ans << std::endl;
}

void binarySearch(int n, int m) {
	int st = 0;
	int en = 10001;
	while (true) {
		if (st > en) {
			return ;
		}
		int mid = (st + en) / 2;
		int split = checkInterval(n, mid);
		if (split > m) {
			st = mid + 1;
		} else {
			if (mid < ans) {
				ans = mid;
			}
			en = mid - 1;
		}
	}
}

int checkInterval(int n, int mid) {
	int split = 1;
	int res = 2147483647;
	int min = 2147483647;
	int max = -2147483648;
	for (int i = 0; i < n; i++) {
		if (vec[i] < min) {
			min = vec[i];
		} 
		if (vec[i] > max) {
			max = vec[i];
		} 
		res = max - min;
		if (res > mid) {
			split += 1;
			min = vec[i];
			max = vec[i];
		}
	}
	return split;
}