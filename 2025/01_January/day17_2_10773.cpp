/*
10773번
제로
실버 4

문제
숫자를 부르면 더하고, 0이면 숫자를 빼는 구현
*/

#include <iostream>
#include <stack>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::stack<int> st;
	while (n--) {
		int num;
		std::cin >> num;
		if (num == 0) {
			st.pop();
		} else {
			st.push(num);
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	std::cout << sum << std::endl;
}