
#include <iostream>
#include <cmath>

int main(void) {
	long long a, b, c;
	while (true) {
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break ;
		}
		a = std::pow(a, 2);
		b = std::pow(b, 2);
		c = std::pow(c, 2);
		if (a + b == c || a + c == b || b + c == a) {
			std::cout << "right\n";
		} else {
			std::cout << "wrong\n";
		}
	}
	return 0;
}