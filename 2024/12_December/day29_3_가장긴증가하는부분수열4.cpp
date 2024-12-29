/*
14002번 골드4 : LIS 알고리즘

수열 A가 있을 때 증가하는 부분 수열 중에 가장 긴 수열을 구하고 그 길이를 출력
이후 그 부분수열을 출력

6
1 9 10 14 3 5

lis
1	3	5	14
pos
0	4	5	3
parent
-1	0	1	2
res
9	10	14
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> arr(n);
	std::vector<std::pair<int, int>> lis;
	std::vector<int> res;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].first;
		// 들어갈 위치 체크
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
		// 들어갈 위치의 인덱스 또한 체크
		int idx = it - lis.begin();
		// 제일 클 경우 추가, 나머지 경우 수정
        if (it == lis.end()) {
            lis.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
		// lis에 들어가는 숫자가 arr의 어느 위치에 있는지 기억
		lis[idx].second = i;
		// 지금 채워지는 숫자가 어떤 숫자 이후로 채워진 것인지 체크하기 위해 사용
		// lis[idx - 1]은 바로 현재 들어가는 숫자가 누구 다음인지 확인할 수 있음
		if (idx > 0) {
			arr[i].second = lis[idx - 1].second;
		} else {
			arr[i].second = -1;
		}
	}
	std::pair<int, int> tracking = arr[lis[lis.size() - 1].second];
	while (true) {
		res.insert(res.begin(), tracking.first);
		if (tracking.second == -1) {
			break ;
		}
		tracking = arr[tracking.second];
	}
	int length = res.size();
	std::cout << length << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << res[i];
		if (i != length - 1) {
			std::cout << " ";
		} else {
			std::cout << "\n";
		}
	}
}