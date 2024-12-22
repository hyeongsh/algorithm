
#include <iostream>

int map[129][129];

void checkNum(int n, int &white, int &blue, int x, int y);

int main(void) {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
		}
	}
	int white = 0, blue = 0;
	checkNum(n, white, blue, 0, 0);
	std::cout << white << std::endl;
	std::cout << blue << std::endl;
}

void checkNum(int n, int &white, int &blue, int x, int y) {
	int flag = 0;
	int check = map[x][y];
	if (n != 1) {
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (map[i][j] != check) {
					flag = 1;
					break ;
				}	
			}
			if (flag) {
				break ;
			}
		}
	}
	if (flag) {
		int nextN = n / 2;
		checkNum(nextN, white, blue, x, y);
		checkNum(nextN, white, blue, x, y + nextN);
		checkNum(nextN, white, blue, x + nextN, y);
		checkNum(nextN, white, blue, x + nextN, y + nextN);
	} else {
		if (check == 0) {
			white++;
		} else if (check == 1) {
			blue++;
		}
	}
}
