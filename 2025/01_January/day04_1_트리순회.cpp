/*
1991번 실버1

이진 트리를 입력받아 전위 순회, 중위 순회, 후위 순회 결과 출력
*/

#include <iostream>
#include <map>

void preTraversal(std::map<char, std::pair<char, char>> &tree, std::string &preOrder, char cur);
void inTraversal(std::map<char, std::pair<char, char>> &tree, std::string &inOrder, char cur);
void postTraversal(std::map<char, std::pair<char, char>> &tree, std::string &postOrder, char cur);


int main(void) {
	int n;
	std::cin >> n;
	std::map<char, std::pair<char, char>> tree;

	for (int i = 0; i < n; i++) {
		char root, left, right;
		std::cin >> root >> left >> right;
		tree.insert({root, {left, right}});
	}
	std::string preOrder;
	std::string inOrder;
	std::string postOrder;

	preTraversal(tree, preOrder, 'A');
	inTraversal(tree, inOrder, 'A');
	postTraversal(tree, postOrder, 'A');
	std::cout << preOrder << std::endl;
	std::cout << inOrder << std::endl;
	std::cout << postOrder << std::endl;
}

void preTraversal(std::map<char, std::pair<char, char>> &tree, std::string &preOrder, char cur) {
	preOrder.push_back(cur);
	std::map<char, std::pair<char, char>>::iterator iter = tree.find(cur);
	if (iter->second.first != '.') {
		preTraversal(tree, preOrder, iter->second.first);
	}
	if (iter->second.second != '.') {
		preTraversal(tree, preOrder, iter->second.second);
	}
}

void inTraversal(std::map<char, std::pair<char, char>> &tree, std::string &inOrder, char cur) {
	std::map<char, std::pair<char, char>>::iterator iter = tree.find(cur);
	if (iter->second.first != '.') {
		inTraversal(tree, inOrder, iter->second.first);
	}
	inOrder.push_back(cur);
	if (iter->second.second != '.') {
		inTraversal(tree, inOrder, iter->second.second);
	}
}

void postTraversal(std::map<char, std::pair<char, char>> &tree, std::string &postOrder, char cur) {
	std::map<char, std::pair<char, char>>::iterator iter = tree.find(cur);
	if (iter->second.first != '.') {
		postTraversal(tree, postOrder, iter->second.first);
	}
	if (iter->second.second != '.') {
		postTraversal(tree, postOrder, iter->second.second);
	}
	postOrder.push_back(cur);
}