/*
제목: 용감한 용사 진수
번호: 14718번
난이도: 골드 4

문제
N명의 적이 힘, 민첩, 지능 3가지 능력치를 가진다.
진수의 3개의 능력이 적 병사보다 크거나 같으면 병사를 이긴다.
k명의 병사를 이길 수 있는 최소의 스탯 포인트를 출력하여라.

*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <algorithm>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
struct Stat {
	int strength;
	int agility;
	int intell;
};

int N, K;
Stat soldiers[101];

// 기본 함수
void input();
void findAnswer();
int checkNum(int strength, int agility, int intell);

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		std::cin >> soldiers[i].strength >> soldiers[i].agility >> soldiers[i].intell;
	}
}

void findAnswer() {
	int minStrength = 2e9;
	int minAgility = 2e9;
	int minIntell = 2e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int curStrength = soldiers[i].strength;
				int curAgility = soldiers[j].agility;
				int curIntell = soldiers[k].intell;
				if (checkNum(curStrength, curAgility, curIntell) >= K) {
					if (minStrength + minAgility + minIntell > curStrength + curAgility + curIntell) {
						minStrength = curStrength;
						minAgility = curAgility;
						minIntell = curIntell;
					}
				}
			}
		}
	}
	std::cout << minStrength + minAgility + minIntell << std::endl;
}

int checkNum(int strength, int agility, int intell) {
	// std::cout << strength << " " << agility << " " << intell << std::endl;
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (strength >= soldiers[i].strength && agility >= soldiers[i].agility && intell >= soldiers[i].intell) {
			num++;
		}
	}
	return num;
}
