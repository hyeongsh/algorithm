/*
9663번
N-Queen
골드 4

N x N 개의 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
N이 주어졌을 때 퀸을 놓는 방법의 수
재귀 탐색
*/

#include <iostream>

int board[15][15];
int ans;

void recurChess(int n, int cur);
bool check(int a, int b, int n);

int main(void) {
	int n;
	std::cin >> n;
	recurChess(n, 0);
	std::cout << ans << std::endl;
}

void recurChess(int n, int cur) {
	if (cur == n) {
		ans++;
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (check(cur, i, n)) {
			board[cur][i] = 1;
			recurChess(n, cur + 1);
		}
		board[cur][i] = 0;
	}
}

bool check(int a, int b, int n) {
	for (int i = a - 1, j = b - 1, k = b + 1; i >= 0; i--, j--, k++) {
		if (board[i][b]) {
			return false;
		} else if (j >= 0 && board[i][j]) {
			return false;
		} else if (k < n && board[i][k]) {
			return false;
		}
	}
	return true;
}