
#include <iostream>
#include <vector>

void dfs(int table[6][3], int home, int away, int *re);

int main(void) {
	int result[4];
	for (int a = 0; a < 4; a++) {
		int table[6][3];
		int check = 1;
		int re = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				std::cin >> table[i][j];
			}
			if (table[i][0] + table[i][1] + table[i][2] != 5) {
				check = 0;
			}
		}
		if (check) {
			dfs(table, 0, 1, &re);
		}
		result[a] = re;
	}
	for (int i = 0; i < 4; i++) {
		std::cout << result[i];
		if (i != 3) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
}

void dfs(int table[6][3], int home, int away, int *re) {
	if (home == 5) {
		*re = 1;
		return ;
	}
	int nexthome;
	int nextaway;
	if (away >= 5) {
		nexthome = home + 1;
		nextaway = nexthome + 1;
	} else {
		nexthome = home;
		nextaway = away + 1;
	}
	if (table[home][0] > 0 && table[away][2] > 0) {
		table[home][0]--;
		table[away][2]--;
		dfs(table, nexthome, nextaway, re);
		if (*re) {
			return ;
		}
		table[home][0]++;
		table[away][2]++;
	}
	if (table[home][1] > 0 && table[away][1] > 0) {
		table[home][1]--;
		table[away][1]--;
		dfs(table, nexthome, nextaway, re);
		if (*re) {
			return ;
		}
		table[home][1]++;
		table[away][1]++;
	}
	if (table[home][2] > 0 && table[away][0] > 0) {
		table[home][2]--;
		table[away][0]--;
		dfs(table, nexthome, nextaway, re);
		if (*re) {
			return ;
		}
		table[home][2]++;
		table[away][0]++;
	}
}

// 5 0 0  3 0 2  2 0 3  0 0 5  4 0 1  1 0 4
// 4 1 0  3 0 2  4 1 0  1 1 3  0 0 5  1 1 3
// 5 0 0  4 0 1  2 2 1  2 0 3  1 0 4  0 0 5
// 5 0 0  3 1 1  2 1 2  2 0 3  0 0 5  1 0 4

// a : b 승((0,0),(1,2)) 무((0,1),(1,1)) 패((0,2),(1,0)) -> 실패

// a : c 승((0,0),(2,2)) 무((0,1),(2,1)) 패((0,2),(2,0))

// a : d 승((0,0),(3,2)) 무((0,1),(3,1)) 패((0,2),(3,0))

// a : e 승((0,0),(4,2)) 무((0,1),(4,1)) 패((0,2),(4,0))

// a : f 승((0,0),(5,2)) 무((0,1),(5,1)) 패((0,2),(5,0))

// b : c 승((1,0),(2,2)) 무((1,1),(2,1)) 패((1,2),(2,0))

// b : d 승((1,0),(3,2)) 무((1,1),(3,1)) 패((1,2),(3,0))

// b : e 승((1,0),(4,2)) 무((1,1),(4,1)) 패((1,2),(4,0))

// b : f 승((1,0),(5,2)) 무((1,1),(5,1)) 패((1,2),(5,0))

// c : d 승((2,0),(3,2)) 무((2,1),(3,1)) 패((2,2),(3,0))

// c : e 승((2,0),(4,2)) 무((2,1),(4,1)) 패((2,2),(4,0))

// c : f 승((2,0),(5,2)) 무((2,1),(5,1)) 패((2,2),(5,0))

// d : e 승((3,0),(4,2)) 무((3,1),(4,1)) 패((3,2),(4,0))

// d : f 승((3,0),(5,2)) 무((3,1),(5,1)) 패((3,2),(5,0))

// e : f 승((4,0),(5,2)) 무((4,1),(5,1)) 패((4,2),(5,0))

// 성공
