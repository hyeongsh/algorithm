/*
제목: 아우으 우아으이야!!
번호: 15922번
난이도: 골드 5

문제
수직선 위에 그려진 선분 길이의 총합 구하기
겹쳐질 수도 있으니 겹친 부분은 제외해야 한다.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100001

// 전역 변수 선언
int N;
std::vector<std::pair<int, int>> lines(MAX);

// 기본 함수
void input();
void findAnswer();

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		std::cin >> a >> b;
		lines[i] = {a, b};
	}
}

void findAnswer() {
	int left = lines[0].first;
	int right = lines[0].second;
	int sum = 0;
	for (int i = 1; i < N; i++) {
		if (right >= lines[i].first) {
			right = std::max(right, lines[i].second);
		} else {
			sum += right - left;
			left = lines[i].first;
			right = lines[i].second;
		}
	}
	sum += right - left;
	std::cout << sum << std::endl;
}
