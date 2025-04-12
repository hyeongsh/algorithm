/*
제목: 미친 아두이노
번호: 8972
난이도: 골드 3

문제
상하좌우 대각선 이동 가능, 정지도 가능
미친 아두이노는 8가지 방향 중 거리가 가장 가까워지는 방향 선택
미친 아두이노가 있는 칸으로 이동하거나 미친 아두이노가 자신이 있는 칸에 이동하면 게임 종료
미친 아두이노 여러개가 같은 칸에 있는 경우 아두이노 폭파
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <map>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 101

// 전역 변수 선언
int R, C;
int curA, curB;
char board[MAX][MAX];
std::string move;
std::map<std::pair<int, int>, bool> arduinos;
int da[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int db[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

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
	std::cin >> R >> C;
	for (int i = 0; i < R; i++) {
		std::string line;
		std::cin >> line;
		for (int j = 0; j < C; j++) {
			if (line[j] == 'I') {
				curA = i;
				curB = j;
				board[i][j] = line[j];
			} else if (line[j] == 'R') {
				arduinos.insert({{i, j}, false});
				board[i][j] = '.';
			} else {
				board[i][j] = line[j];
			}
		}
	}
	std::cin >> move;
}

void findAnswer() {
	int size = move.size();
	for (int i = 0; i < size; i++) {
		std::map<std::pair<int, int>, bool> nextArd;
		board[curA][curB] = '.';
		curA += da[move[i] - '0'];
		curB += db[move[i] - '0'];
		board[curA][curB] = 'I';
		int ardSize = arduinos.size();
		for (const auto &ard : arduinos) {
			if (ard.second) {
				continue ;
			}
			int ardA = ard.first.first;
			int ardB = ard.first.second;
			if (ardA < curA) {
				ardA += 1;
			} else if (ardA > curA) {
				ardA -= 1;
			}
			if (ardB < curB) {
				ardB += 1;
			} else if (ardB > curB) {
				ardB -= 1;
			}
			if (board[ardA][ardB] == 'I') {
				std::cout << "kraj " << i + 1 << std::endl;
				return ;
			}
			if (nextArd.find({ardA, ardB}) == nextArd.end()) {
				nextArd.insert({{ardA, ardB}, false});
			} else {
				nextArd[{ardA, ardB}] = true;
			}
		}
		arduinos = nextArd;
	}
	for (const auto &ard : arduinos) {
		if (ard.second) {
			continue ;
		}
		int ardA = ard.first.first;
		int ardB = ard.first.second;
		board[ardA][ardB] = 'R';
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}
