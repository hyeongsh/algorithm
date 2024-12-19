
#include <iostream>
#include <vector>

std::vector<int> vec(6);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < (int)vec.size(); i++) {
		std::cin >> vec[i];
	}
	int t, p;
	std::cin >> t >> p;
	int count = 0;
	for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		count += (*iter) / t + ((*iter) % t != 0);
	}
	std::cout << count << std::endl;
	std::cout << n / p << " " << n % p << std::endl;
}