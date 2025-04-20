/*
제목: 점 모으기
번호: 7571번
난이도: 골드5

문제
N 크기의 지도에 M 개의 점들이 있을때, 이걸 한 곳으로 모으는 최솟값을 구하는 문제

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, M;
std::vector<int> vecA;
std::vector<int> vecB;

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

long long calDist(int a, int b);

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
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		vecA.push_back(a);
		vecB.push_back(b);
	}
}

void setting() {
	std::sort(vecA.begin(), vecA.end());
	std::sort(vecB.begin(), vecB.end());
}

void findAnswer() {
	int a = vecA[M / 2];
	int b = vecB[M / 2];
	std::cout << calDist(a, b) << std::endl;
}

long long calDist(int a, int b) {
	long long dist = 0;
	if (a < 1 || b < 1 || a > N || b > N) {
		return 1e9;
	}
	for (int i = 0; i < M; i++) {
		dist += std::abs(a - vecA[i]) + std::abs(b - vecB[i]);
	}
	return dist;
}
