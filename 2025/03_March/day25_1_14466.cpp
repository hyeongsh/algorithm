/*
소가 길을 건너간 이유 6
14466번
골드 3

문제
길이 주어지지 않으면 자유롭게 건너갈 수 있음
길이 주어진 곳은 길로밖에 못감
길을 건너야만 만날 수 있는 쌍을 구해야 함.

0	0	0

0	2	0
	|	|
0	3 -	1

*/

#include <iostream>
#include <queue>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
#define MAX 101

int n, k, r;
int map[MAX][MAX];
bool road[MAX][MAX][4];
std::vector<std::pair<int, int>> cow;
int answer;

int da[4] = {-1, 1, 0, 0};
int db[4] = {0, 0, -1, 1};

void init();
void input();
void setting();
void findAnswer();

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
	std::cin >> n >> k >> r;
	for (int i = 0; i < r; i++) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		if (a < c) {
			road[a][b][1] = true;
			road[c][d][0] = true;
		} else if (a > c) {
			road[a][b][0] = true;
			road[c][d][1] = true;
		} else if (b < d) {
			road[a][b][3] = true;
			road[c][d][2] = true;
		} else {
			road[a][b][2] = true;
			road[c][d][3] = true;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		std::cin >> a >> b;
		cow.push_back({a, b});
	}
}

void setting() {
	int size = cow.size();
	std::queue<std::pair<int, int>> que;
	int vis[MAX][MAX] = {0, };
	for (int i = 0; i < size; i++) {
		init();
		que.push(cow[i]);
		vis[cow[i].first][cow[i].second] = true;
		while (!que.empty()) {
			int curA = que.front().first;
			int curB = que.front().second;
			que.pop();
			for (int j = 0; j < 4; j++) {
				if (road[curA][curB][j]) {
					continue ;
				}
				int nextA = curA + da[j];
				int nextB = curB + db[j];
				if (nextA >= 1 && nextB >= 1 && nextA <= n && nextB <= n && !vis[nextA][nextB]) {
					que.push({nextA, nextB});
					vis[nextA][nextB] = true;
				}
			}
		}
		for (int j = i + 1; j < size; j++) {
			if (!vis[cow[j].first][cow[j].second]) {
				answer++;
			}
		}
	}
}

void findAnswer() {
	std::cout << answer << std::endl;
}