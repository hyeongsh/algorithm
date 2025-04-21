/*
제목: 영우는 사기꾼?
번호: 14676번
난이도: 골드 4

문제
건물을 짓기 위해선 테크 트리를 따라야 하는데, 건설 및 파괴 정보를 보고 치트로 만든 건물인지 알아내야 한다.
*/

// 라이브러리 설정
#include <iostream>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, M, K;
int needPrev[100001];
int curBuild[100001];
std::vector<std::vector<int>> tech(100001);

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
	std::cin >> N >> M >> K;
	for (int m = 0; m < M; m++) {
		int x, y;
		std::cin >> x >> y;
		tech[x].push_back(y);
		needPrev[y]++;
	}
	for (int k = 0; k < K; k++) {
		int act, building;
		std::cin >> act >> building;
		if (act == 1) {
			if (needPrev[building] > 0) {
				std::cout << "Lier!" << std::endl;
				return ;
			} else if (curBuild[building] == 0) {
				for (int next : tech[building]) {
					needPrev[next]--;
				}
			}
			curBuild[building]++;
		} else {
			if (curBuild[building] == 0) {
				std::cout << "Lier!" << std::endl;
				return ;
			} else if (curBuild[building] == 1) {
				for (int next : tech[building]) {
					needPrev[next]++;
				}
			}
			curBuild[building]--;
		}
	}
	std::cout << "King-God-Emperor" << std::endl;
}

void findAnswer() {
	;
}
