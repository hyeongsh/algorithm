
#include <iostream>

int main(void) {
	int e, s, m;
	std::cin >> e >> s >> m;
	int ans = 1;
	while (true) {
		if (ans % 15 == e % 15 && ans % 28 == s % 28 && ans % 19 == m % 19) {
			break ;
		}
		ans++;
	}
	std::cout << ans << std::endl;
}

// 1 16 16		16
// 15의 배수 + 1이면서, 28의 배수 + 16, 19의 배수 + 16
// 1 1 1		1
// 1 2 3		5266
// 15 28 19		7980

// -> 1이면 나머지가 1이라는 뜻