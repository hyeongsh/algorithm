/*
1628번 실버1

a를 b번 곱한 값을 c로 나눈 값 구하기

(a^b) % c

모듈러 분배 규칙 활용
(a * a) % b = (a % b) * (a % b) % b

*/

#include <iostream>

long long power(long long a, int b, int c);

int main(void) {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << power(a, b, c) << std::endl;
}

long long power(long long a, int b, int c) {
	long long answer = 1;
	while (b > 0) {
		if (b % 2) {
			answer *= a;
			answer %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}
	return answer;
}