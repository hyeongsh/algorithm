/*
연산자 끼워넣기
14888번
실버 1

문제
N개의 수로 이루어진 수열 A1, A2, ..., An
N-1개의 연산자  (+, -, *, /)
수의 순서를 바꾸지 않고 수식을 만들어서 최대인 것과 최소인 것을 구해라.
연산자 우선 순위는 무시하며, 정수 나눗셈으로 몫만 취한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int n;
int max = -2147483648;
int min = 2147483647;
std::vector<int> vec(12);
std::vector<int> oper(4);

void bt(int res, int cur);

int main(void) {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	for (int i = 0; i < 4; i++) {
		std::cin >> oper[i];
	}

	bt(vec[0], 1);
	std::cout << max << std::endl;
	std::cout << min << std::endl;
}

void bt(int res, int cur) {
	if (cur == n) {
		if (max < res) {
			max = res;
		}
		if (min > res) {
			min = res;
		}
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			int prev = res;
			switch (i) {
				case 0:
					res = res + vec[cur];
					break ;
				case 1:
					res = res - vec[cur];
					break ;
				case 2:
					res = res * vec[cur];
					break ;
				case 3:
					res = res / vec[cur];
					break ;
			}
			bt(res, cur + 1);
			oper[i]++;
			res = prev;
		}
	}
}