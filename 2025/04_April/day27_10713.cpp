/*
제목: 기차 여행
번호: 10713번
난이도: 골드 4

문제
철도를 타는 방법은 티켓을 구입해 승차하는 방법과 ic 카드로 승차하는 방법이 있음
티켓을 구입해 승차하면 A원이 들고, ic카드로 승차하면 B원이 드는데, 한번 구매할 때 C원을 쓰고 계속 사용할 수 있다.
ic카드로 타는게 조금 더 싸고 ic카드나 티켓은 전부 다 딱 그 철도에서만 탈 수 있다고 가정한다.
1번 도시에서 출발해 매일 다음 도시를 방문해서 M번째 도시까지 가는데 드는 최소 비용을 출력해라.
*/

// 라이브러리 설정
#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
#define MAX 100001

struct Price {
	int ticket;
	int toll;
	int card;
};

// 전역 변수 선언
int N, M;
int order[MAX];
int rails[MAX];
int info[MAX];
Price prices[MAX];


// 기본 함수
void input();
void setting();
void findAnswer();

// main 함수
int main(void) {
	FASTIO
	input();
	setting();
	findAnswer();
}

void input() {
	std::cin >> N >> M;
	int prev;
	for (int i = 0; i < M; i++) {
		std::cin >> order[i];
		if (i != 0) {
			int cur = order[i];
			int minCity = std::min(prev, cur);
			int maxCity= std::max(prev, cur);
			info[minCity]++;
			info[maxCity]--;
		}
		prev = order[i];
	}
	for (int i = 1; i < N; i++) {
		std::cin >> prices[i].ticket >> prices[i].toll >> prices[i].card;
	}
}

void setting() {
	int change = 0;
	for (int i = 1; i < N; i++) {
		change += info[i];
		rails[i] = change;
	}
}

void findAnswer() {
	long long sum = 0;
	for (int i = 1; i < N; i++) {
		sum += std::min((long long)prices[i].ticket * rails[i], prices[i].card + (long long)prices[i].toll * rails[i]);
	}
	std::cout << sum << std::endl;
}
