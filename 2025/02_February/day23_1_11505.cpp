/*
구간 곱 구하기
11505번
골드 1

문제
N개의 수. 수의 변경이 빈번히 일어나며 어떤 부분의 곱을 구해야 하는 문제
예) 1, 2, 3, 4, 5 중 3번째 수를 6으로 바꾸고 2번~5번까지의 곱 계산 -> 2 * 6 * 4 * 5 = 240

입력
N, M, K 가 주어지고 N개의 수가 M번 변경되고 K번 계산해야 한다.
*/

#include <iostream>

#define MOD_NUM 1000000007

int arr[1000001];
long long segTree[4000001];

int init(int st, int en, int curNode);
int update(int st, int en, int curNode, int index, int change);
int calculate(int st, int en, int curNode, int b, int c);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
			// for (int i = 1; i <= 4 * n; i++) {
			// 	std::cout << i << ": " << segTree[i] << std::endl;
			// }
		} else {
			std::cout << calculate(1, n, 1, b, c) << std::endl;
		}
	}
	return 0;
}

int init(int st, int en, int curNode) {
	if (st == en) {
		segTree[curNode] = arr[st];
		return segTree[curNode];
	}
	segTree[curNode] 
		= init(st, st + (en - st) / 2, curNode * 2)
		* init(st + 1 + (en - st) / 2, en, curNode * 2 + 1);
	segTree[curNode] %= MOD_NUM;
	return segTree[curNode];
}

int update(int st, int en, int curNode, int index, int change) {
	if (st == en) {
		segTree[curNode] = change;
		return segTree[curNode];
	} else if (index >= st && index <= en) {
		segTree[curNode]
			= update(st, st + (en - st) / 2, curNode * 2, index, change)
			* update(st + 1 + (en - st) / 2, en, curNode * 2 + 1, index, change);
		return segTree[curNode];
	} else {
		return segTree[curNode];
	}
}

int calculate(int st, int en, int curNode, int b, int c) {
	if (st <= b && en >= c) {
		return segTree[curNode];
	} else if (st >= c || en <= b) {
		return 1;
	} else {
		return (calculate(st, st + (en - st) / 2, curNode * 2, b, c)
			* calculate(st + 1 + (en - st) / 2, en, curNode * 2 + 1, b, c)) % MOD_NUM;
	}
}