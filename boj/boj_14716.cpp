
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
int arr[251][251];

int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
int visit[251][251];

void bfs(int _y, int _x)
{
	visit[_y][_x] = true;
	queue<pair<int, int>>qu;
	qu.push({ _y,_x });

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 8; i++)
		{
			int my = y + dy[i];
			int mx = x + dx[i];

			if (visit[my][mx])
				continue;
			if (mx < 0 || my < 0 || mx >= M || my >= N)
				continue;
			if (arr[my][mx] == 0)
				continue;
			if (arr[my][mx] == 1)
			{
				visit[my][mx] = true;
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

	//백준 14716
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (!visit[i][j] && arr[i][j] == 1)
			{
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt;
}
