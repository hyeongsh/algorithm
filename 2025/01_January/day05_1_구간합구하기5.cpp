/*
11660번 실버1

N x N 표에 숫자가 채워져있을 때, x1, y1 부터 x2, y2 까지의 합을 구해야 함.
한줄로 되어 있을 경우엔 a ~ b까지의 합은 b까지의 총합 - a까지의 총합
2차원으로 되어 있는 경우엔?
b까지의 총합 - (yb - ya)까지의 총합 - (xb - xa)까지의 총합 + a이전까지의 총합
*/

#include <iostream>

int arr[1025][1025];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
			arr[i][j] += arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 1];
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << arr[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	
	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		int total = arr[x2][y2];
		int totalX = arr[x1 - 1][y2];
		int totalY = arr[x2][y1 - 1];
		int totalXY = arr[x1 - 1][y1 - 1];
		int ans = total - totalX - totalY + totalXY;
		std::cout << ans << "\n";
	}

}