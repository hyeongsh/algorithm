
#include <iostream>
#include <vector>
#include <numeric>

int arr[100001];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::cin >> arr[0];
	for (int i = 1; i < n; i++) {
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int start;
		int last;
		std::cin >> start >> last;
		if (start == 1) {
			std::cout << arr[last - 1] << "\n";	
		} else {
			std::cout << arr[last - 1] - arr[start - 2] << "\n";
		}
		
	}
}

/*
0	1	2	3	4
5	9	12	14	15

*/
