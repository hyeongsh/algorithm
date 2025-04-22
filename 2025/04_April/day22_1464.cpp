/*
제목: 뒤집기 3
번호: 1464번
난이도: 골드 4

문제
길이 1부터 N까지 뒤집기를 해야 함.
뒤집기는 해도 되고, 안해도 됨
문자열 중 사전순으로 가장 앞서는 것을 만들어야 함
DBQCDXACFAGN
010001101100
BDQCDXACFAGN
XDCQDBACFAGN
ABDQCDXCFAGN
FCXDCQDBAAGN
AABDQCDXCFGN
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
std::string S;
std::string min;
int reverse[51];

// 기본 함수
void input();
void findAnswer();
void test(std::string str, int cur, int size);
void reverseCheck(std::string str, bool flag);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> S;	
}

void findAnswer() {
	// 테스트 코드
	int size = S.size();
	// min = S;
	// test(S, 0, S.size());
	// std::cout << min << std::endl;

	reverseCheck(S, false);
	for (int i = 0; i < size; i++) {
		if (reverse[i] == 1) {
			std::reverse(S.begin(), S.begin() + i + 1);
		}
	}
	std::cout << S << std::endl;
}

void test(std::string str, int cur, int size) {
	if (cur == size) {
		if (min > str) {
			min = str;
		}
		return ;
	}
	test(str, cur + 1, size);
	std::reverse(str.begin(), str.begin() + cur + 1);
	test(str, cur + 1, size);
}

void reverseCheck(std::string str, bool flag) {
	int size = str.size();
	if (size <= 1) {
		return ;
	}
	int minChar = 'Z';
	int minPos = size;
	for (int i = 0; i < size; i++) {
		if (str[i] <= minChar) {
			minChar = str[i];
			minPos = i;
		}
	}
	reverse[minPos] = !reverse[minPos];
	if (flag == true) {
		reverse[size - 1] = !reverse[size - 1];
	}
	reverseCheck(str.substr(0, minPos), true);
}