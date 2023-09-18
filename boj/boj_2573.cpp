
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


int N, M;
const int MAX = 301;
int arr[MAX][MAX];
int visit[MAX][MAX];
int temp[MAX][MAX];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool visist[MAX][MAX];

void check(int y, int x)
{
	queue<pair<int, int >> qu;
	visit[y][x] = true;
	qu.push(make_pair(y, x));

	while (!qu.empty())
	{
		int _y = qu.front().first;
		int _x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int my = _y + dy[i];
			int mx = _x + dx[i];

			if (mx < 0 || my < 0 || mx >= M || my >= N)
				continue;
			if (arr[my][mx] == 0) //바다면 패스 (육지의 갯수를 check)
				continue;
			if (visit[my][mx])
				continue;

			qu.push({ my, mx });
			visit[my][mx] = true;
		}
	}
}

void meltIce()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0) //물이면 패스
				continue;

			int cnt = 0;
			for (int p = 0; p < 4; p++)
			{
				int my = i + dy[p];
				int mx = j + dx[p];

				if (mx < 0 || my < 0 || mx >= M || my >= N)
					continue;

				if (arr[my][mx] == 0)
					cnt++;
			}

			int val = arr[i][j] - cnt; //물의갯수 빼기
			if (val > 0)
				temp[i][j] = val;
		}
	}

	//빙하 구현 한다음 arr에 대입해줌
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 2573
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int year = 0;
	while (true)
	{
		memset(visit, false, sizeof(visit)); //검사하기전에 visit초기회 (bfs로 검사위해)
		int len = 0; // bfs로 검사한 구간
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && arr[i][j] != 0)
				{
					check(i, j); // bfs로 구역 구하기
					len++;
				}
			}
		}
		if (len == 0)
		{
			cout << 0;
			break;
		}
		if (len >= 2)
		{
			cout << year;
			break;
		}

		//그게 아니면 
		year++;
		//빙하녹이기
		meltIce();
	}
}
