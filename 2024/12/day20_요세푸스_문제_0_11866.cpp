
#include <iostream>
#include <vector>

int main(void) {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		vec[i] = i + 1;
	}
	int cur = -1;
	std::cout << "<";
	for (int i = 0; i < n; i++) {
		cur = (cur + k) % vec.size();
		std::cout << vec[cur];
		if (i != n - 1) {
			std::cout << ", ";
		}
		vec.erase(vec.begin() + cur);
		cur--;
	}
	std::cout << ">" << std::endl;
}

// 1 4
// 3 -> 6 -> 2 -> 7 -> 5 -> 1 -> 4