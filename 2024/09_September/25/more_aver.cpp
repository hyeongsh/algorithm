
#include <iostream>
#include <vector>
#include <numeric>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int c;
	std::cin >> c;
	std::cout << std::fixed;
	std::cout.precision(3);
	for (int i = 0; i < c; i++) {
		int n;
		std::cin >> n;
		std::vector<double> vec(n);
		for (int j = 0; j < n; j++) {
			std::cin >> vec[j];
		}
		double average = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
		double more = 0;
		for (int j = 0; j < n; j++) {
			if (vec[j] > average) {
				more++;
			}
		}
		std::cout << more / n * 100 << "%" << std::endl;
	}
}