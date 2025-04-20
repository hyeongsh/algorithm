/*
제목: 비밀번호 만들기
번호: 17218번
난이도: 골드 4

문제
두 문자열 중 가장 긴 부분 문자열을 비밀번호로 설정
최대 길이는 40자이며 가장 긴 부분 문자열은 하나만 존재한다.
LCS 알고리즘을 사용한다.
*/

// 라이브러리 설정
#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 41

// 전역 변수 선언
std::vector<std::vector<int>> vec(MAX, std::vector<int>(MAX, 0));
std::string A;
std::string B;

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

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
	std::cin >> A >> B;
}

void setting() {
	int aSize = A.size();
	int bSize = B.size();
	for (int i = 0; i < aSize; i++) {
		for (int j = 0; j < bSize; j++) {
			if (A[i] == B[j]) {
				vec[i + 1][j + 1] = vec[i][j] + 1;
			} else {
				vec[i + 1][j + 1] = std::max(vec[i + 1][j], vec[i][j + 1]);
			}
		}
	}
	// for (int i = 0; i <= aSize; i++) {
	// 	std::cout << i << ":	";
	// 	for (int j = 0; j <= bSize; j++) {
	// 		std::cout << vec[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
}

void findAnswer() {
	std::string ans;
	int a = A.size();
	int b = B.size();
	int size = vec[a][b];
	while (vec[a][b]) {
		if (vec[a - 1][b] < vec[a][b] && vec[a][b - 1] < vec[a][b]) {
			ans.insert(ans.begin(), B[b - 1]);
			a--;
			b--;
		} else if (vec[a - 1][b] < vec[a][b]) {
			b--;
		} else {
			a--;
		}
	}
	std::cout << ans << std::endl;
}