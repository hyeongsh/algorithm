
#include <iostream>

int check(int L, int O, int V, int E) {
	return ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100;
}

int main(void) {
	std::string name;
	int n;
	int prob[4] = {0, };
	int win = 0;
	std::string love = "LOVE";
	std::string win_team = "ZZZZZZZZZZZ";

	std::cin >> name;
	for (int i = 0; i < name.size(); i++) {
		for (int j = 0; j < 4; j++) {
			if (name[i] == love[j]) {
				prob[j]++;
				continue ;
			}
		}
	}
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string team;
		int prob2[4] = {0, };
		std::cin >> team;
		for (int j = 0; j < team.size(); j++) {
			for (int k = 0; k < 4; k++) {
				if (team[j] == love[k]) {
					prob2[k]++;
					continue ;
				}
			}
		}
		int team_win = check(prob[0] + prob2[0], prob[1] + prob2[1], prob[2] + prob2[2], prob[3] + prob2[3]);
		if (win < team_win || (win == team_win && team <= win_team)) {
			win_team = team;
			win = team_win;
		}
	}
	std::cout << win_team << std::endl;
}
