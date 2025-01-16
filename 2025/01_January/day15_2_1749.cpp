/*
1749번
점수따먹기
골드 4

문제 N * M 행렬의 최대합을 출력하라
*/

#include <iostream>

int arr[201][201];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
			arr[i][j] += arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 1];
		}
	}
	int max = -10000;
	for (int x2 = 1; x2 <= n; x2++) {
		for (int y2 = 1; y2 <= m; y2++) {
			for (int x1 = 1; x1 <= x2; x1++) {
				for (int y1 = 1; y1 <= y2; y1++) {
					int total = arr[x2][y2];
					int totalX = arr[x1 - 1][y2];
					int totalY = arr[x2][y1 - 1];
					int totalXY = arr[x1 - 1][y1 - 1];
					int ans = total - totalX - totalY + totalXY;
					if (max < ans) {
						max = ans;
					}
				}
			}
		}
	}
	std::cout << max << std::endl;
}