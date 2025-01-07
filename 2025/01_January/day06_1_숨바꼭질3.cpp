/*
13549번 골드5

수빈 : 점 N
동생 : 점 K

걷거나 순간이동 가능
걷기 : 1초 후 x - 1, x + 1
순간이동 : 0초 후 2x

6 42
0	0	1	1	2	2
6	12	11	22	21	42

1 6
0	0	1	1
1	2	3	6

1 100000
100000 50000 25000 12500 6250 3125 3124 1562 781 780 390 195 194 97 96 48 24 12 6 3 2 1
*/

#include <iostream>
#include <queue>

int arr[100001];
int vis[100001];

void checkStep(std::queue<int> &que, int cur, int next, int plus);

int main(void) {
	int n, k;
	std::cin >> n >> k;
	std::queue<int> que;
	que.push(n);
	vis[n] = 1;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		int nextStep = cur + 1;
		int prevStep = cur - 1;
		int doubleStep = cur * 2;
		checkStep(que, cur, nextStep, 1);
		checkStep(que, cur, prevStep, 1);
		checkStep(que, cur, doubleStep, 0);
	}
	std::cout << arr[k] << std::endl;
}

void checkStep(std::queue<int> &que, int cur, int next, int plus) {
	if (next < 0 || next > 100000) {
		return ;
	}
	if (!vis[next]) {
		arr[next] = arr[cur] + plus;
		vis[next] = 1;
		que.push(next);
	} else if (arr[next] > arr[cur] + plus) {
		arr[next] = arr[cur] + plus;
		que.push(next);
	}
}