/*
제목: 샘터
번호: 18513번
난이도: 골드 4

문제
N개의 샘터, K채의 집 (모든 샘터와 집들은 서로 다른 위치에 존재한다)
집과 샘터가 멀수록 불행도 증가
최소한의 불행도를 구하여야 함.
샘물 정렬 -> 0 5 14 27 38 , 집 100채 설치
가장 적게 차이나는게 0과 5 -> 사이 4칸, 8칸, 12칸, 10칸
1칸 -> 쌉가능 총 10채 넣을 수 있음 + 10
2칸 -> 쌉가능 총 10채 넣을 수 있음 + 20
3칸 -> 총 8채 넣을 수 있음 + 24, 0의 오른쪽과 5의 왼쪽이 겹침
4칸 -> 총 8채 넣을 수 있음 + 32,
5칸 -> 총 6채 넣을 수 있음 + 30, 5의 오른쪽과 14의 왼쪽이 겹침
6칸 -> 총 4채 넣을 수 있음 + 24, 27의 오른쪽과 38의 왼쪽이 겹침
7칸 -> 총 2채 넣을 수 있음 + 14, 14의 오른쪽과 27의 왼쪽이 겹침
8칸 -> 2채 + 16
9칸 -> 2채 + 18
여기서 고려해야 할 것. (-1억과 +1억이 넘는지 체크해야 함.)
*/

// 라이브러리 설정
#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, K;
std::vector<int> sam;
std::vector<int> samDist;

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
		int pos;
		std::cin >> pos;
		sam.push_back(pos);
	}
}

void findAnswer() {
	std::sort(sam.begin(), sam.end());
	int size = sam.size();
	for (int i = 0; i < size - 1; i++) {
		samDist.push_back(sam[i + 1] - sam[i] - 1);
	}
	std::sort(samDist.begin(), samDist.end());

	long long curDist = 1;
	long long cur = 0;
	long long totalDist = 0;
	while (K > 0) {
		// std::cout << "남은 집: " << K << std::endl;
		// std::cout << "현재 dist: " << curDist << std::endl;
		while (cur < samDist.size() && samDist[cur] < curDist * 2) {
			if (samDist[cur] % 2) {
				totalDist += curDist;
				K -= 1;
			}
			cur++;
		}
		// std::cout << "양쪽에 놓을 수 있는 개수: " << (size - cur) << std::endl;
		totalDist += curDist * (size - cur) * 2;
		// std::cout << "현재 불행도: " << totalDist << std::endl;
		K -= (size - cur) * 2;
		curDist++;
		// std::cout << "-------------------------------------" << std::endl;
	}
	if (K < 0) {
		totalDist += (curDist - 1) * K;
	}
	std::cout << totalDist << std::endl;
}
