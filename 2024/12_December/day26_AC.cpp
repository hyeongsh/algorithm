/*
5430번 골드 5

AC는 정수 배열 연산을 위한 언어
R함수 : 배열 순서를 뒤집는 함수
D함수 : 첫 번째 수를 버리는 함수, 비어 있을 때는 에러

테스트케이스 수
반복
	수행할 함수
	배열 크기
	배열 정수

배열 개수 < D의 개수 -> error
R -> D를 뒤에서 빼기
RR-> D를 앞에서 빼기

*/

#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
	int t;
	std::string cmd;
	int n;
	std::string arr;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> cmd >> n >> arr;
		std::string subString;
		std::vector<int> vec(n);
		int cur = 0;
		for (int j = 1; j < arr.size() - 1; j++) {
			if (arr[j] == ',') {
				cur++;
			} else {
				vec[cur] = vec[cur] * 10 + (arr[j] - '0');
			}
		}
		int r = 0;
		int flag = 0;
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R') {
				r++;
			} else if (vec.empty()) {
				flag = 1;
				break ;
			} else if (r % 2 == 0) {
				vec.erase(vec.begin());
			} else {
				vec.erase(vec.end() - 1);
			}
		}
		if (flag) {
			std::cout << "error" << std::endl;
		} else if (r % 2 == 0) {
			std::cout << "[";
			for (int j = 0; j < vec.size(); j++) {
				std::cout << vec[j];
				if (j < vec.size() - 1) {
					std::cout << ",";
				}
			}
			std::cout << "]\n";
		} else {
			std::cout << "[";
			for (int j = vec.size() - 1; j >= 0; j--) {
				std::cout << vec[j];
				if (j > 0) {
					std::cout << ",";
				}
			}
			std::cout << "]\n";
		}
	}
}