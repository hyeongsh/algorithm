/*
2805번

나무 M미터
H를 결정하면 나열되어 있는 나무들을 전부 H미터 만큼 잘라 그 윗부분을 가져갈 것임.
M미터를 만들기 위한 H의 최댓값
N은 1,000,000 M은 2,000,000,000 이므로 단순 탐색으로는 불가능
정렬 -> 큰 거부터 차례대로 빼내면 될듯.
100만 정렬은 시간 초과 나나?

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> trees(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> trees[i];
	}
	trees[n] = 0;
	std::sort(trees.begin(), trees.end(), [](int a, int b) {
		return a > b;
	});
	int h = trees[0];
	int curTree = 0;
	int curM = 0;
	while (true) {
		long long nextCurM = curM + (long long)(trees[curTree] - trees[curTree + 1]) * (curTree + 1);
		if (nextCurM < m) {
			curM = nextCurM;
			h -= trees[curTree] - trees[curTree + 1];
			curTree++;
		} else {
			while (curM < m) {
				curM += curTree + 1;
				h -= 1;
			}
			break ;
		}
	}
	std::cout << h << std::endl;
}
