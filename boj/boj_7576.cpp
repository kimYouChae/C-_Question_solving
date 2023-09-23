
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

int N, M, R;
int arr[1001][1001];

queue<pair<int, int>> qu;
int dx[] = { 0 , 1 , 0 , -1 };
int dy[] = { 1 , 0 , -1 , 0 };

int visit[1001][1001];
void bfs()
{
	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int my = y + dy[i];
			int mx = x + dx[i];

			if (mx < 0 || my < 0 || mx >= N || my >= M)
				continue;
			if (visit[my][mx] != -1)
				continue;

			if (arr[my][mx] == 0)
			{
				visit[my][mx] = visit[y][x] + 1;
				qu.push({ my,mx });
			}

		}

	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준  7576
	cin >> N >> M;

	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 익은 토마토라면 -> bfs queue에 넣어놓으면
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				qu.push({ i,j });
				visit[i][j] = 0;
			}
		}
	}


	bfs();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}

	int answer = -1;
	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (answer <= visit[i][j])
			{
				answer = visit[i][j];
			}

			if (arr[i][j] == 0 && visit[i][j] == -1)
			{
				answer = -1;
				flag = true;
				break;
			}

		}
		if (flag)
			break;
	}

	cout << answer;
}
