
#include <iostream>

int callTime[4000] = {0, };

int main(void) {
	int N, L, D;
	std::cin >> N >> L >> D;
	int cur = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			callTime[cur++] = 1;
		}
		cur += 5;
	}
	cur = 0;
	while (true) {
		if (callTime[cur] == 0) {
			break ;
		}
		cur += D;
	}
	std::cout << cur << std::endl;
}
