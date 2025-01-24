/*
3671번
산업 스파이의 편지
골드 5

문제
숫자를 배치해서 소수가 되는 경우를 찾아라
*/

#include <iostream>

#define MAX_NUM 10000000 

int nonPrime[MAX_NUM];
int vis[MAX_NUM];

int primeCheck(std::string res, std::string str, int size, int c);

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	nonPrime[0] = 1;
	nonPrime[1] = 1;
	for (int i = 2; i * i <= MAX_NUM; i++) {
		if (!nonPrime[i]) {
			for (int j = i + i; j < MAX_NUM; j += i) {
				nonPrime[j] = 1;
			}
		}
	}
	int c;
	std::cin >> c;
	while (c--) {
		std::string str;
		std::cin >> str;
		int num = 0;
		for (size_t i = 1; i <= str.size(); i++) {
			num += primeCheck("", str, i, c + 1);
		}
		std::cout << num << std::endl;
	}
}

int primeCheck(std::string res, std::string str, int size, int c) {
	if (size == 0) {
		int resNum = std::strtod(res.c_str(), nullptr);
		if (vis[resNum] != c && !nonPrime[resNum]) {
			vis[resNum] = c;
			return 1;
		} else {
			return 0;
		}
	}
	int num = 0;
	for (size_t i = 0; i < str.size(); i++) {
		std::string newStr(str);
		res.push_back(str[i]);
		newStr.erase(newStr.begin() + i);
		num += primeCheck(res, newStr, size - 1, c);
		res.pop_back();
	}
	return num;
}