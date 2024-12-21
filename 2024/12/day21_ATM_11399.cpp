
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(void) {
	int n;
	std::cin >> n;
	std::vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += vec[i] * (n - i);
	}
	std::cout << sum << std::endl;

}