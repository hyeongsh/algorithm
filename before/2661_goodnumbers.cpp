
#include <iostream>

std::string num;
int n;

bool recur(int depth);
bool isInvalid(int size);

int main(void) {
	std::cin >> n;
	recur(0);
	std::cout << num << std::endl;
}

bool recur(int depth) {
	if (depth != 0 && isInvalid(depth)) {
		return false;
	} else if (depth == n) {
		return true;
	}
	num.append("1");
	if (recur(depth + 1)) {
		return true;
	}
	num.erase(depth);
	num.append("2");
	if (recur(depth + 1)) {
		return true;
	}
	num.erase(depth);
	num.append("3");
	if (recur(depth + 1)) {
		return true;
	}
	num.erase(depth);
	return false;
}

bool isInvalid(int size) {
	for (int i = 1; i <= size / 2; i++) {
		std::string src = num.substr(size - i, i);
		std::string dest = num.substr(size - i * 2, i);
		if (src == dest) {
			return true;
		}
	}
	return false;
}


// 1
// 1
// 2
// 12
// 3
// 121
// 4
// 1213
// 5
// 12131
// 6
// 121312
// 7
// 1213121
// 8
// 12131231
// 9
// 121312312
// 10
// 1213123121

