/*
제목: 고기잡이
번호: 7573번
난이도: 골드3

문제
점이 무작위로 주어지고, 주어진 길이만으로 직사각형으로 만들때 점들을 가장 많이 묶을 수 있어야 함.
그때의 점 개수를 출력.
*/

// 라이브러리 설정
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, I, M;
std::vector<std::pair<int, int>> fishes;

// 기본 함수
void input();
void findAnswer();

int checkFishes(int a, int b, int aSize, int bSize);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N >> I >> M;
	fishes.push_back({1, 1});
	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		fishes.push_back({a, b});
	}
}

void findAnswer() {
	int maxDist = I / 2;
	int maxCount = 0;
	for (int i = 0; i < M; i++) {
		for (int garo = maxDist - 1, sero = 1; garo > 0; garo--, sero++) {
			int standardA = fishes[i].first;
			int standardB = fishes[i].second;
			for (int j = 0; j <= garo; j++) {
				int count = checkFishes(standardA, standardB, sero, garo);
				if (maxCount < count) {
					// std::cout << "change: " << standardA << " " << standardB << std::endl;
					// std::cout << "changeSize: " << sero << " " << garo << std::endl;
					// std::cout << "count: " << count << std::endl;
					maxCount = count;
				}
				standardB--;
			}
		}
	}
	std::cout << maxCount << std::endl;
}

int checkFishes(int a, int b, int aSize, int bSize) {
	if (a < 1 || b < 1 || a + aSize > N || b + bSize > N) {
		return 0;
	}
	int count = 0;
	for (int i = 1; i <= M; i++) {
		if (fishes[i].first - a >= 0 && fishes[i].first - a <= aSize && fishes[i].second - b >= 0 && fishes[i].second - b <= bSize) {
			count++;
		}
	}
	return count;
}