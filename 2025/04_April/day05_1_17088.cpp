/*
제목: 등차수열 변환
번호: 17088번
난이도: 골드5

문제
수열을 등차수열로 변환.
1을 더하거나 1을 빼서 변환하되, 각각의 수에는 연산을 최대 한번만 적용하여야 함.

25
20
15
10
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <climits>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100001

// 전역 변수 선언
int N;
int arr[MAX];
int res = INT_MAX;

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

int changeSeq(int s, int n, int count);

// main 함수
int main(void) {
	FASTIO
	init();
	input();
	setting();
	findAnswer();
}

void init() {
	
}

void input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
}

void setting() {
	int s[3] = {arr[0], arr[0] + 1, arr[0] - 1};
	int n[3] = {arr[1], arr[1] + 1, arr[1] - 1};
	int count;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			count = changeSeq(s[i], n[j], (i != 0) + (j != 0));
			if (count != -1 && count < res) {
				res = count;
			}
		}
	}

}

void findAnswer() {
	if (res == INT_MAX) {
		res = -1;
	}
	std::cout << res << std::endl;
}

int changeSeq(int s, int n, int count) {
	int diff = s - n;
	for (int i = 2; i < N; i++) {
		n = n - diff;
		if (arr[i] == n) {
			continue ;
		} else if (arr[i] + 1 == n) {
			count++;
			continue ;
		} else if (arr[i] - 1 == n) {
			count++;
			continue ;
		} else {
			return -1;
		}
	}
	return count;
}