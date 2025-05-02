/*
제목: 나는 기말고사형 인간이야
번호: 23254번
난이도: 골드 5

문제
기말고사 시작은 24 x N 시간 후이며 M개의 과목 시험을 치루게 된다.
공부를 하지 않을 시 a점, 1시간 공부할 때마다 b점씩 증가한다.
최종 성적의 최댓값을 출력하라.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 200001

// 전역 변수 선언
int N, M;
std::priority_queue<std::pair<int, int>> pq;
std::vector<std::pair<int, int>> grades(MAX);

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
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> grades[i].second;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> grades[i].first;
	}
	for (int i = 0; i < M; i++) {
		pq.push(grades[i]);
	}
}

void findAnswer() {
	int sum = 0;
	int timeOut = N * 24;
	while (!pq.empty() && timeOut) {
		int grade = pq.top().second;
		int up = pq.top().first;
		pq.pop();
		int hours = std::min(timeOut, (100 - grade) / up);
		int newGrade = grade + hours * up;
		if (newGrade == 100) {
			sum += 100;
		} else if (newGrade < 100) {
			pq.push({100 - newGrade, newGrade});
		}
		timeOut -= hours;
	}
	while (!pq.empty()) {
		sum += pq.top().second;
		pq.pop();
	}
	std::cout << sum << std::endl;
}
