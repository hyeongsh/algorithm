
#include <iostream>
#include <vector>
#include <set>

long long factorial(long long n);

int main(void) {
	int n;
	int quest;
	std::cin >> n;
	std::vector<int> permut(n);
	std::set<int> numset;
	for (int i = 1; i <= n; i++) {
		numset.insert(i);
	}
	std::cin >> quest;
	if (quest == 1) {
		long long order;
		std::cin >> order;
		for (int i = 0; i < n; i++) {
			long long tmp = factorial(n - 1 - i);
			long long mut = (order - 1) / tmp;
			std::set<int>::iterator iter = numset.begin();
			for (long long j = 0; j < mut; j++) {
				iter++;
			}
			permut[i] = *iter;
			numset.erase(iter);
			order = order - tmp * mut;
		}
		for (size_t i = 0; i < permut.size(); i++) {
			std::cout << permut[i] << " ";		
		}
		std::cout << std::endl;
	} else {
		long long order = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> permut[i];
			long long tmp = factorial(n - 1 - i);
			long long k = 0;
			for (std::set<int>::iterator iter = numset.begin(); iter != numset.end(); iter++, k++) {
				if (*iter == permut[i]) {
					order += k * tmp;
					numset.erase(iter);
					break ;
				}
			}
		}
		std::cout << order << std::endl;
	}
}

long long factorial(long long n) {
	if (n == 0) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}