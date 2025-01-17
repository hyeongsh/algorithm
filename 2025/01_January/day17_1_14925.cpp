/*
14925번
목장 건설하기
골드 4

문제
목장을 정사각형으로 지으려 하는데, 가장 큰 정사각형을 찾아야 하는 문제
0으로만 구성되어야 하고 그 안에 나무와 바위는 없어야 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void printVec(std::vector<std::vector<int>> &vec);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int m, n;
	std::cin >> m >> n;
	std::vector<std::vector<int>> myMap(m + 1, std::vector<int>(n + 1));
	std::vector<std::vector<int>> rectSize(m + 1, std::vector<int>(n + 1));
	int max = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> myMap[i][j];
			if (myMap[i][j] == 0) {
				int minSize = std::min(rectSize[i - 1][j], std::min(rectSize[i][j - 1], rectSize[i - 1][j - 1]));
				rectSize[i][j] = minSize + 1;
				if (rectSize[i][j] > max) {
					max = rectSize[i][j];
				}
			}
		}
	}
	//printVec(rectSize);
	std::cout << max << std::endl;
}

void printVec(std::vector<std::vector<int>> &vec) {
	int iSize = vec.size();
	int jSize = vec[0].size();
	std::cout << "----------------------\n";
	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < jSize; j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------\n";
}