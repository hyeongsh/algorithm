/*
중앙값 측정
9426번
플레 5

문제
최대길이가 n인 수열에서 길이가 k인 모든 연속 부분 수열의 중앙값의 합을 출력하라.
예) 3 4 5 6 7 8 9 10 11 12
	중앙값: 4, 5, 6, 7, 8, 9, 10, 11 / 합: 60

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 250,000, 1 ≤ K ≤ 5,000, K ≤ N)
둘째 줄부터 N개 줄에 측정한 온도가 순서대로 주어진다. 온도는 0보다 크거나 같고, 65535보다 작거나 같은 정수이다.
*/

#include <iostream>
#include <algorithm>

int arr[250001];
int segTree[300001];

void init(int st, int en, int index, int value);
long long check(int st, int en, int index, int median);
void remove(int st, int en, int index, int value);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	int median = (k + 1) / 2;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
		init(0, 65535, 1, arr[i]);
		if (i >= k) {
			sum += check(0, 65535, 1, median);
			remove(0, 65535, 1, arr[i - k + 1]);
		}
	}
	std::cout << sum << std::endl;
}

void init(int st, int en, int index, int value) {
	if (value < st || en < value) {
		return ;
	} else if (st == en) {
		segTree[index] += 1;
		return ;
	}
	int mid = (st + en) / 2;
	init(st, mid, index * 2, value);
	init(mid + 1, en, index * 2 + 1, value);
	segTree[index] = segTree[index * 2] + segTree[index * 2 + 1];
}

long long check(int st, int en, int index, int median) {
	if (st == en) {
		return st;
	}
	int mid = (st + en) / 2;
	// std::cout << "cur: " << segTree[index] << " st~en: " << st << "~" << en << std::endl;
	if (median <= segTree[index * 2]) {
		return check(st, mid, index * 2, median);
	} else {
		median -= segTree[index * 2];
		return check(mid + 1, en, index * 2 + 1, median);
	}
}

void remove(int st, int en, int index, int value) {
	if (value < st || en < value) {
		return ;
	} else if (st == en) {
		segTree[index] -= 1;
		return ;
	}
	int mid = (st + en) / 2;
	remove(st, mid, index * 2, value);
	remove(mid + 1, en, index * 2 + 1, value);
	segTree[index] = segTree[index * 2] + segTree[index * 2 + 1];
}
