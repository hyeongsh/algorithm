/*
15650번 실버3

1부터 N까지의 자연수 중에서 M개를 고른 수열을 찾아야함
고른 수열은 오름차순이어야함
수열들 또한 사전 순으로 출력해야 한다.

*/

#include <iostream>
#include <vector>

void permutation(int n, int m, int cur, std::vector<int> &vec);

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vec(m + 1);
	permutation(n, m, 1, vec);
}

void permutation(int n, int m, int cur, std::vector<int> &vec) {
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
	for (int i = vec[cur - 1] + 1; i <= n - m + cur; i++) {
		vec[cur] = i;
		permutation(n, m, cur + 1, vec);
	}
}