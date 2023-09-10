
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
const int MAX = 501;
int arr[MAX][MAX];
int dp[MAX][MAX];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int dfs(int x, int y) // dp는 -1로 초기화되어있음
{
	if (x == N - 1 && y == M - 1) // 도착지에 도착하면 ?
	{
		return 1;
	}
	if (dp[x][y] != -1) //방문했으면? 
	{
		return dp[x][y];
	}

	dp[x][y] = 0; //방문은 했으니까 0으로
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my <0 || mx >= N || my >M)
		{
			continue;
		}

		// 계단수여서 다음으로 넘어갈수 있으면?
		if (arr[mx][my] < arr[x][y])
		{
			dp[x][y] = dp[x][y] + dfs(mx, my);
		}
	}

	// 최종 정답을 return?
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 1520
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	// dp[][]가 -1 : 아직 방문하지 x
	// dp[][]가 0 : 0개 

	int answer = dfs(0, 0);
	cout << answer;
}
