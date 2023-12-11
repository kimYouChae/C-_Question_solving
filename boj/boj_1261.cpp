/*
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
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

const int MAX = 101;
const int INF = 100000;
int arr[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int dp[MAX][MAX];

void bfs_01()
{
	// bfs를 기준으로 
	queue < pair<int, int>> qu;
	qu.push({ 0,0 });	// 처음은 0
	dp[0][0] = 0;	// 맨 처음 가중치는 0

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		// 상하좌우 4방향
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			// 범위 밖에 나가면
			if (nextY < 0 || nextX < 0 || nextY >= M || nextX >= N)
				continue;

			// 벽 일때
			if (arr[nextY][nextX] == 1)
			{
				//dp 값 갱신
				if (dp[nextY][nextX] > dp[y][x] + 1)
				{
					dp[nextY][nextX] = dp[y][x] + 1;
					qu.push({ nextY , nextX });
				}

			}
			// 벽이 아닐때
			else if (arr[nextY][nextX] == 0)
			{
				//dp 값 갱신
				if (dp[nextY][nextX] > dp[y][x])
				{
					dp[nextY][nextX] = dp[y][x];
					qu.push({ nextY , nextX });
				}
			}
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
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			char ch = str[j];
			arr[i][j] = ch - '0';
			dp[i][j] = INF;	// 일단 제일 큰 값으로
		}
	}

	bfs_01();
	cout << dp[M - 1][N - 1];

}
*/
