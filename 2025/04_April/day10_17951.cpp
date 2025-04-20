/*
제목: 흩날리는 시험지 속에서 내 평점이 느껴진거야
번호: 17951번
난이도: 골드 3

문제
시험지의 개수 N과 시험지를 나눌 그룹의 수 K가 정수로 주어진다.
각 시험지마다 맞은 문제의 개수 x가 정수로 주어진다.
받을 수 있는 최대 점수를 출력하라.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 100001

// 전역 변수 선언
int N, K;
int sum;
std::vector<int> scores(MAX);

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
	std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		std::cin >> scores[i];
		sum += scores[i];
	}
}

void findAnswer() {
	int st = 0;
	int en = sum;
    int mid;
    int res = 0;
	while (st <= en) {
		mid = (st + en) / 2;
		int group = 0;
		int check = 0;
		for (int i = 0; i < N; i++) {
			check += scores[i];
			if (check >= mid) {
				group++;
				check = 0;
			}
		}
		if (group >= K) {
			st = mid + 1;
		} else if (group < K) {
			en = mid - 1;
		}
	}
    std::cout << en << std::endl;
}
