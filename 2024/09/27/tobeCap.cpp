
#include <iostream>

int apart[15][15];

int main(void) {
	int t;
	std::cin >> t;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (i == 0) {
				apart[i][j] = j + 1;
			} else if (j == 0) {
				apart[i][j] = 1;
			} else {
				apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
			}
		}
	}
	for (int i = 0; i < t; i++) {
		int n, k;
		std::cin >> k >> n;
		std::cout << apart[k][n - 1] << std::endl;
	}
}

/*

0층 1	2	3	4	5	6	7	8	9
1층 1	3	6	10	15	21	28	36	45
2층 1	4	10	20	35	46	74	110	155	-> 1 * 3 + 2 * 2 + 3 * 1
3층 1	5	15	35	.	.	.	.	.	-> 

2
1 3
2 3

6
10

*/

