
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M;
int arr[1001][1001];
int dp[1001][1001] = { 0, }; //0으로 초기화

int dx[] = { 1,0,1 };
int dy[] = { 0,1,1 };

void getSum(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my < 0 || mx >= M || my >= N) //범위에 벗어나면 
		{
			continue;
		}

		//그게 아니면
		int num = dp[x][y] + arr[mx][my]; //dp[mx][my]에 들어갈값
		if (dp[mx][my] != 0) // 이미 들어간 값이 있다면
		{
			// 원래 있떤 값이랑 새로 구한거랑 비교해서 더 큰거를 dp[mx][my]에 넣어야함
			int Nmax = max(dp[mx][my], num);
			dp[mx][my] = Nmax;
		}
		else
		{
			dp[mx][my] = num;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지 7
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[j][i];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			getSum(j, i);
		}
	}

	//dp배열을 출력해보자
	cout << dp[M - 1][N - 1];

}
