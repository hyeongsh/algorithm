
#include <iostream>
#include <string>
#include <stack>

std::stack<int> st;

void st_push();
void st_pop();
int st_top();

int main(void) {
	int n;
	std::cin >> n;
	std::cin.ignore(10, '\n');
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (str == "push") {
			st_push();
		} else if (str == "pop") {
			st_pop();
		} else if (str == "top") {
			int num = st_top();
			std::cout << num << std::endl;
		} else if (str == "size") {
			std::cout << st.size() << std::endl;
		} else if (str == "empty") {
			std::cout << st.empty() << std::endl;
		}
	}
}

void st_push() {
	int num;
	std::cin >> num;
	st.push(num);
}

void st_pop() {
	int out = st_top();
	if (out != -1) {
		st.pop();
	}
	std::cout << out << std::endl;
}

int st_top() {
	if (st.empty()) {
		return -1;
	}
	return st.top();
}
