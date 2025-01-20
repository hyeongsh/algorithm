/*
1874번
스택 수열
실버 2

문제
스택에 push하는 순서는 반드시 오름차순을 지킨다.
스택을 이용해 주어지는 수열을 만들 수 있는지, 있다면 어떻게 수행해야 하는지 출력해라
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	std::string ans = "";
	std::vector<int> vec(n + 1);
	std::stack<int> st;
	for (int i = 0; i < n; i++) {
		std::cin >> vec[i];
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		st.push(i);
		ans += "+\n";
		while (!st.empty() && st.top() == vec[cur]) {
			st.pop();
			ans += "-\n";
			cur++;
		}
	}
	if (!st.empty()) {
		std::cout << "NO\n";
	} else {
		std::cout << ans;
	}
}
