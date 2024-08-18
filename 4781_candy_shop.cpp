
#include <iostream>
#include <vector>
#include <algorithm>

int dp[10002];

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	double m;
	std::cin >> n >> m;
	while (n != 0 && m != 0) {
		std::fill(&dp[0], &dp[10001] + 1, 0);
		int money = static_cast<int>(m * 100 + 0.5);
		int c;
		double p;
		int cost;
		std::vector<std::pair<int, int> > vec;
		for (int i = 0; i < n; i++) {
			std::cin >> c >> p;
			cost = static_cast<int>(p * 100 + 0.5);
			dp[cost] = std::max(dp[cost], c);
			vec.push_back(std::make_pair(c, cost));
		}
		for (int i = 1; i <= money; i++) {
			if (dp[i] > dp[i - 1]) {	
				for (size_t j = 0; j < vec.size(); j++) {
					if (i + vec[j].second <= money) {
						dp[i + vec[j].second] = std::max(dp[i] + vec[j].first, dp[i + vec[j].second]);
					}
				}
			} else {
				dp[i] = dp[i - 1];
			}
		}
		std::cout << dp[money] << std::endl;
		std::cin >> n >> m;
	}
}