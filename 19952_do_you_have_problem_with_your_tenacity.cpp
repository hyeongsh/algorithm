#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, H, W, O, F, YS, XS, YE, XE;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            Visited[i][j] = false;
            MAP[i][j] = 0;
        }
    }
}

bool BFS() {
    queue<pair<pair<int, int>, int> > Q;
    Visited[YS][XS] = true;
    Q.push(make_pair(make_pair(YS, XS), F));
	while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowF = Q.front().second;
        int NowH = MAP[NowY][NowX];
        Q.pop();

        if ((NowY == YE) && (NowX == XE)) {
            return true;
        }

        if (NowF == 0) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 1) && (NextY <= H) && (NextX >= 1) && (NextX <= W)) {
                if (NowH >= MAP[NextY][NextX]) {
                    if (!Visited[NextY][NextX]) {
                        Visited[NextY][NextX] = true;
                        Q.push(make_pair(make_pair(NextY, NextX), NowF - 1));
                    }
                }
                else {
                    int SubH = MAP[NextY][NextX] - NowH;
                    if (NowF >= SubH) {
                        if (!Visited[NextY][NextX]) {
                            Visited[NextY][NextX] = true;
                            Q.push(make_pair(make_pair(NextY, NextX), NowF - 1));
                        }
                    }
                }
            }
        }
    };
return false;
}

void find_Answer() {
    bool Flag = BFS();
    if (Flag) {
        cout << "잘했어!!\n";
    }
    else {
        cout << "인성 문제있어??\n";
    }
}

void input() {
    cin >> T;
    while (T--) {
        init();
        cin >> H >> W >> O >> F >> YS >> XS >> YE >> XE;
        for (int i = 0; i < O; i++) {
            int A, B, C;
            cin >> A >> B >> C;
            MAP[A][B] = C;
        }
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}

