
// 안되는 풀이
/*
int N, M, R;
int mx, my, by, bx;
const int MAX = 301;
char arr[MAX][MAX];


int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0 ,1, 0, -1 };

bool flag = false;

void bfs(int _y, int _x)
{
	bool visit[MAX][MAX];
	memset(visit, false, sizeof(visit));	//visit 초기화

	queue<pair<int, int>> q;
	q.push({ _y, _x });
	visit[_y][_x] = true;

	while (!q.empty())
	{
		int cY = q.front().first;
		int cX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = cY + dy[i];
			int nextX = cX + dx[i];

			// 만약 도착 칸까지 도착하면?
			if (arr[nextY][nextX] == '#')
			{
				flag = true;
				return;
			}

			if (nextY < 1 || nextX < 1 || nextY > N || nextX > M)
				continue;

			if (visit[nextY][nextX] == true)
				continue;

			// 그게 아니면 
			// 방문처리
			visit[nextY][nextX] = true;

			// 다음 좌표가 1이면 > 0으로 바꾸기
			if (arr[nextY][nextX] == '1')
				arr[nextY][nextX] = '0';

			// 다음 좌표가 0이면 > 큐에 넣기 (파장이 계속 퍼짐
			else if (arr[nextY][nextX] == '0')
				q.push({ nextY, nextX });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;
	cin >> mx >> my >> by >> bx;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	while (true)
	{
		answer++;	// 한번 점프하고, 파장(bfs)돌리고
		bfs(my, mx);
		if (flag)	// 도착하면 
			break;
	}
	cout << answer;
}

*/

// 뭐가 안되는지 모르겠음 
// 되는풀이
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, x_1, y_1, x_2, y_2, y, x, ny, nx, ret;
bool ok = false;
char graph[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx) {
	bool visited[304][304];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		y = q.front().first; x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			ny = y + dy[d];
			nx = x + dx[d];
			if (graph[ny][nx] == '#') {
				ok = true;
				return;
			}
			if (ny >= 1 and ny <= N and nx >= 1 and nx <= M and !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (graph[ny][nx] == '1') graph[ny][nx] = '0';
				else if (graph[ny][nx] == '0') q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> graph[i][j];
	}
	while (1) {
		ret++;
		bfs(x_1, y_1);
		if (ok) break;
	}
	cout << ret;
}

