
#include <iostream>
#include <cmath>

int recurLocation(int n, int r, int c);
int z[2][2] = {{0, 1}, {2, 3}};

int main(void) {
	int n, r, c;
	std::cin >> n >> r >> c;
	std::cout << recurLocation(n, r, c) << std::endl;
}

int recurLocation(int n, int r, int c) {
	if (n == 1) {
		return z[r][c];
	}
	int size = std::pow(2, n);
	int sum = 0;
	if (r >= size / 2) {
		r = r - size / 2;
		sum += size * size / 2;
	}
	if (c >= size / 2) {
		c = c - size / 2;
		sum += size * size / 4;
	}
	return sum + recurLocation(n - 1, r, c);
}

// 2 3 1		11
// 3 7 7		63
// 1 0 0		0
// 4 7 7		63
// 10 511 511	262143