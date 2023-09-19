
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
int arr[101][101];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool visit[101][101];
int answer = 0;
int cnt;

void dfs(int y, int x)
{
	cnt += 1;
	visit[y][x] = true; //방문했으면 true
	for (int i = 0; i < 4; i++)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		if (mx <= 0 || my <= 0 || mx > M || my > N)
			continue;
		if (visit[my][mx] == true)
			continue;
		if (arr[my][mx] == 0)
			continue;

		visit[my][mx] = true;
		dfs(my, mx);


	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++)
	{
		int y, x;
		cin >> y >> x;

		arr[y][x] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visit[i][j] && arr[i][j] == 1)
			{
				cnt = 0;
				dfs(i, j);
				answer = max(cnt, answer);
			}

		}
	}

	cout << answer;
}
