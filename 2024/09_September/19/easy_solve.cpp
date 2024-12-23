
#include <iostream>

int arr[1001] = {0, };

int main(void) {
	int a, b;
	std::cin >> a >> b;
	int st = 1;
	int en = 1;
	for (int i = 1; i < 1001; i++) {
		if (st > en) {
			en++;
			st = 1;
		}
		arr[i] = en;
		st++;
	}
	int ans = 0;
	for (int i = a; i <= b; i++) {
		ans += arr[i];
	}
	std::cout << ans << std::endl;
}
