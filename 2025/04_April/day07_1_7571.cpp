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
#include <cstdlib>
#include <numeric>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, M;
std::pair<int, int> average;
std::vector<std::pair<int, int>> vec;
int da[4] = {1, -1, 0, 0};
int db[4] = {0, 0, 1, -1};

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
	int a, b;
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		vec.push_back({a, b});
	}
}

void setting() {
	average = std::accumulate(vec.begin(), vec.end(), std::make_pair(0, 0), 
		[](const std::pair<int, int> &a, const std::pair<int, int> &b) {
			return std::make_pair(a.first + b.first, a.second + b.second);
		}
	);
	average.first /= M;
	average.second /= M;
}

void findAnswer() {
	int curA = average.first;
	int curB = average.second;
	long long minDist;
	while (true) {
		long long dist = calDist(curA, curB);
		minDist = dist;
		int minA = curA;
		int minB = curB;
		for (int i = 0; i < 4; i++) {
			int nextA = curA + da[i];
			int nextB = curB + db[i];
			long long nextDist = calDist(nextA, nextB);
			if (nextDist < dist) {
				minDist = nextDist;
				minA = nextA;
				minB = nextB;
			}
		}
		if (minDist == dist) {
			break ;
		} else {
			curA = minA;
			curB = minB;
		}
	}
	std::cout << minDist << std::endl;
}

long long calDist(int a, int b) {
	long long dist = 0;
	if (a < 1 || b < 1 || a > N || b > N) {
		return 1e9;
	}
	for (int i = 0; i < M; i++) {
		dist += std::abs(a - vec[i].first) + std::abs(b - vec[i].second);
	}
	return dist;
}
