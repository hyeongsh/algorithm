/*
제목: 유닛 이동시키기
번호: 2194번
난이도: 골드 4

문제
N * M 사이즈의 맵에 A * B 사이즈의 유닛이 존재함.
K개의 장애물을 뚫고 시작점에서 끝점으로 최소한의 움직임으로 이동해야 함.
이 과정에서 도착할 수 없는 -1 출력
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 501

// 전역 변수 선언
int N, M;
int A, B;
int K;
int myMap[MAX][MAX];
int vis[MAX][MAX];
int sa, sb, ea, eb;
int da[4] = {1, -1, 0, 0};
int db[4] = {0, 0, 1, -1};

// 기본 함수
void init();
void input();
void setting();
void findAnswer();

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
	std::cin >> A >> B;
	std::cin >> K;
	for (int k = 0; k < K; k++) {
		int ka, kb;
		std::cin >> ka >> kb;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if (ka - i < 1 || kb - j < 1 || ka - i > N - A + 1 || kb - j > M - B + 1) {
					continue ;
				}
				myMap[ka - i][kb - j] = -1;
			}
		}
	}
	std::cin >> sa >> sb;
	std::cin >> ea >> eb;
}

void setting() {
	std::queue<std::pair<int, int>> que;
	que.push({sa, sb});
	vis[sa][sb] = 1;
	while (!que.empty()) {
		int ca = que.front().first;
		int cb = que.front().second;
		// std::cout << "(a, b): " << ca << " " << cb << " / dist: " << vis[ca][cb] << std::endl;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int na = ca + da[i];
			int nb = cb + db[i];
			if (na < 1 || nb < 1 || na > N - A + 1 || nb > M - B + 1) {
				continue ;
			} else if (vis[na][nb] || myMap[na][nb] == -1) {
				continue ;
			} else {
				if (na == ea && nb == eb) {
					vis[na][nb] = vis[ca][cb];
					return ;
				}
				vis[na][nb] = vis[ca][cb] + 1;
				que.push({na, nb});
			}
		}
	}
}

void findAnswer() {
	if (vis[ea][eb] == 0) {
		vis[ea][eb] = -1;
	}
	std::cout << vis[ea][eb] << std::endl;
}
