/*
11444번
피보나치 수 6
골드 2

문제
n번째 피보나치 수를 구하라.
단 n은 1,000,000,000,000,000,000 100경?
1,000,000,007 으로 나눈 나머지를 출력
(Fn-1 + Fn-2) % x = ((Fn-1 % x) + (Fn-2 % x)) % x
*/

#include <iostream>
#include <vector>

#define MOD 1000000007

using Matrix = std::vector<std::vector<long long>>;

long long fib(long long n);
Matrix matPow(Matrix base, long long exp);
Matrix matMult(const Matrix &a, const Matrix &b);

int main(void) {
	long long n;
	std::cin >> n;
	std::cout << fib(n) % MOD << std::endl;
}

long long fib(long long n) {
	if (n == 0) {
		return 0;
	}
	Matrix base = {{1, 1}, {1, 0}};
	Matrix result = matPow(base, n - 1);
	return result[0][0];
}

Matrix matPow(Matrix base, long long exp) {
	Matrix result = {{1, 0}, {0, 1}};

	while (exp) {
		if (exp % 2) {
			result = matMult(result, base);
		}
		base = matMult(base, base);
		exp /= 2;
	}
	return result;
}

Matrix matMult(const Matrix &a, const Matrix &b) {
	Matrix result = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return result;
}
