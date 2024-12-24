/*
1697번 실버2

점 N과 점 K 사이 거리 체크
걷거나 순간이동 가능 -> 전부 1초씩 소모
걸으면 x-1, x+1
순간이동 2x
최소 시간 구하기

*/

#include <iostream>
#include <algorithm>
#include <queue>

int arr[100001];

int main(void) {
	int n, k;
	std::cin >> n >> k;
	std::queue<int> que;
	que.push(n);
	arr[n] = 1;
	while (!que.empty()) {
		int x = que.front();
//		std::cout << x << ": " << arr[x] << std::endl;
		if (x == k) {
			break ;
		}
		que.pop();
		if (x - 1 >= 0 && (arr[x - 1] == 0 || arr[x - 1] > arr[x] + 1)) {
			arr[x - 1] = arr[x] + 1;
			que.push(x - 1);
		} if (x + 1 <= 100000 && (arr[x + 1] == 0 || arr[x + 1] > arr[x] + 1)) {
			arr[x + 1] = arr[x] + 1;
			que.push(x + 1);
		} if (x * 2 <= 100000 && (arr[x * 2] == 0 || arr[x * 2] > arr[x] + 1)) {
			arr[x * 2] = arr[x] + 1;
			que.push(x * 2);
		}
	}
	std::cout << arr[k] - 1 << std::endl;
}