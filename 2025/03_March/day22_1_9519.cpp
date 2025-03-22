/*
졸려
9519번
골드 5

문제
단어가 섞임
1. 마지막 글자가 첫 번째 글자와 두 번째 글자 사이로 이동한다.
2. 뒤에서 두 번째 글자가 두 번째 글자와 세 번째 글자 사이로 이동한다.
3. 뒤에서 k번째 글자는 앞에서부터 k번째와 k+1번째 글자 사이로 이동한다. 
->
a는 그대로
abcdef -> afbecd -> adfcbe -> aedbfc -> acefdb -> abcdef
a -> 0, 0, 0, 0, 0
b -> 1, 2, 4, 3, 5, 1
c -> 2, 4, 3, 5, 1, 2
d -> 3, 5, 1, 2, 4, 3
e -> 4, 3, 5, 1, 2, 4
f -> 5, 1, 2, 4, 3, 5

acefdb -> aed bfc
*/

#include <iostream>

int n;
std::string input;

int main(void) {
	std::cin >> n;
	std::cin >> input;
	int count = 0;
	std::string checkStr(input);
	for (int i = 0; i < n; i++) {
		int size = input.size();
		std::string front;
		std::string back;
		for (int i = 0; i < size; i++) {
			if (i % 2 == 0) {
				front.push_back(checkStr[i]);
			} else {
				back.insert(back.begin(), checkStr[i]);
			}
		}
		checkStr = front + back;
		count++;
		if (checkStr == input) {
			break ;
		}
	}
	if (count < n) {
		n %= count;
		for (int i = 0; i < n; i++) {
			int size = input.size();
			std::string front;
			std::string back;
			for (int i = 0; i < size; i++) {
				if (i % 2 == 0) {
					front.push_back(checkStr[i]);
				} else {
					back.insert(back.begin(), checkStr[i]);
				}
			}
			checkStr = front + back;
			count++;
			if (checkStr == input) {
				break ;
			}
		}
	}
	std::cout << checkStr << std::endl;
}