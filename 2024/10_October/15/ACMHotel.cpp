
#include <iostream>

int main(void) {
	int t;
	int h, w, n;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> h >> w >> n;
		int nh = n % h;
		int nw = n / h + (n % h > 0);
		nh = nh ? nh : h;
		std::cout << std::to_string(nh) + std::to_string(nw / 10) + std::to_string(nw % 10) << std::endl;
	}
}
