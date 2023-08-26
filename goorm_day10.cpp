
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
#include<cmath> // math.pow
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> // sort
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

const int MAX = 204;
int cnt[MAX][MAX], visited[MAX][MAX], pos[2][2];
char command[MAX][MAX];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int Play(int y, int x, int N) {
    memset(visited, 0, sizeof(visited));
    int score = 0;
    visited[y][x] = 1;

    while (1) {
        int dir = -1;
        switch (command[y][x]) {
        case 'R': { dir = 0; break; }
        case 'L': { dir = 1; break; }
        case 'D': { dir = 2; break; }
        case 'U': { dir = 3; break; }
        };

        int moveCnt = cnt[y][x];
        while (moveCnt--) {
            y += dy[dir], x += dx[dir];
            if (y > N) y -= N;
            if (x > N) x -= N;
            if (y == 0) y += N;
            if (x == 0) x += N;
            if (visited[y][x]) goto out;
            visited[y][x] = 1;
        }
    }

out:
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) if (visited[i][j]) score++;
    return score;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) cin >> pos[i][j];
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> cnt[i][j] >> command[i][j];

    int goormScore = Play(pos[0][0], pos[0][1], N);
    int playerScore = Play(pos[1][0], pos[1][1], N);

    if (goormScore > playerScore) cout << "goorm " << goormScore << '\n';
    else cout << "player " << playerScore << '\n';
    return 0;
}