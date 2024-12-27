/*
15652번 실버3

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 됨
오름차순 -> 같은 수는 같은 곳에

*/

#include <iostream>
#include <vector>

void permutation(int n, int m, int cur, std::vector<int> &vec);

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vec(m + 1);
	vec[0] = 1;
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
	for (int i = vec[cur - 1]; i <= n; i++) {
		vec[cur] = i;
		permutation(n, m, cur + 1, vec);
	}
}