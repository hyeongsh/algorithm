/*
1918번
후위 표기식
골드 2

문제
후위 표기식으로 바뀐 식을 출력하시오
*/

#include <iostream>
#include <stack>

bool isOper(char check);
int priority(char check);

int main(void) {
	std::string str;
	std::cin >> str;
	std::string ans;
	std::stack<char> operStack;
	for (const auto &cur : str) {
		if (!isOper(cur)) {
			ans.push_back(cur);
		} else if (cur == '(') {
			operStack.push(cur);
		} else if (cur == ')') {
			while (!operStack.empty()) {
				char stackTop = operStack.top();
				operStack.pop();
				if (stackTop != '(') {
					ans.push_back(stackTop);
				} else {
					break ;
				}
			}
		} else {
			while (!operStack.empty()) {
				char stackTop = operStack.top();
				if (priority(cur) > priority(stackTop)) {
					break ;
				} else {
					ans.push_back(stackTop);
					operStack.pop();
				}
			}
			operStack.push(cur);
		}
	}
	while (!operStack.empty()) {
		ans.push_back(operStack.top());
		operStack.pop();
	}
	std::cout << ans << std::endl;
}

bool isOper(char check) {
	std::string opers = "+-*/()";
	for (size_t i = 0; i < opers.size(); i++) {
		if (check == opers[i]) {
			return true;
		}
	}
	return false;
}

int priority(char check) {
	if (check == '+' || check == '-') {
		return 1;
	} else if (check == '*' || check == '/') {
		return 2;
	} else {
		return 0;
	}
}