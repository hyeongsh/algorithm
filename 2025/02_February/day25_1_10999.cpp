/*
구간 합 구하기 2
10999번
플레 4 

문제
N개의 수. 수의 변경이 빈번히 일어나며 어떤 부분의 합을 구해야 하는 문제

입력
N, M, K 가 주어지고 N개의 수가 M번 변경되고 K번 계산해야 한다.
*/

#include <iostream>

#define MOD_NUM 1000000007

long long arr[1000001];
long long segTree[4000004];
long long lazy[4000004];

long long init(int st, int en, int curNode);
long long update(int st, int en, int curNode, int b, int c, long long value);
long long calculate(int st, int en, int curNode, int b, int c);
void push(int st, int en, int curNode);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}
	init(1, n, 1);
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << i << ": " << arr[i] << std::endl;
	// }
	for (int i = 0; i < m + k; i++) {
		int a;
		std::cin >> a;
		if (a == 1) {
			long long b, c, d;
			std::cin >> b >> c >> d;
			update(1, n, 1, b, c, d);
			// for (int i = 1; i <= n; i++) {
			// 	std::cout << i << ": " << arr[i] << std::endl;
			// }
		} else {
			long long b, c;
			std::cin >> b >> c;
			std::cout << calculate(1, n, 1, b, c) << std::endl;
		}
	}
	return 0;
}

long long init(int st, int en, int curNode) {
	if (st == en) {
		segTree[curNode] = arr[st];
		lazy[curNode] = 0;
		return segTree[curNode];
	}
	int mid = (st + en) / 2;
	segTree[curNode] = init(st, mid, curNode * 2) + init(mid + 1, en, curNode * 2 + 1);
	lazy[curNode] = 0;
	return segTree[curNode];
}

long long update(int st, int en, int curNode, int b, int c, long long value) {
	push(st, en, curNode);
	if (b <= st && c >= en) {
		segTree[curNode] += (en - st + 1) * value;
		if (st != en) {
			lazy[curNode * 2] += value;
			lazy[curNode * 2 + 1] += value;
		} else {
			arr[st] = segTree[curNode];
		}
		return segTree[curNode];
	} else if (st > c || en < b) {
		return segTree[curNode];
	} else {
		int mid = (st + en) / 2;
		segTree[curNode]
			= update(st, mid, curNode * 2, b, c, value) + update(mid + 1, en, curNode * 2 + 1, b, c, value);
		return segTree[curNode];
	}
}

long long calculate(int st, int en, int curNode, int b, int c) {
	push(st, en, curNode);
	if (b <= st && c >= en) {
		return segTree[curNode];
	} else if (st > c || en < b) {
		return 0;
	} else {
		int mid = (st + en) / 2;
		return calculate(st, mid, curNode * 2, b, c) + calculate(mid + 1, en, curNode * 2 + 1, b, c);
	}
}

void push(int st, int en, int curNode) {
	if (lazy[curNode] != 0) {
		segTree[curNode] += (en - st + 1) * lazy[curNode];
		if (st != en) {
			lazy[curNode * 2] += lazy[curNode];
			lazy[curNode * 2 + 1] += lazy[curNode];
		} else {
			arr[st] = segTree[curNode];
		}
		lazy[curNode] = 0;
	}
}