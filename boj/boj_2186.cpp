
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

int N, M, K, R, C;
const int MAX = 101;
char arr[MAX][MAX];
int dp[MAX][MAX][80];	// y, x, 좌표 알파벳이 n번째단어일때 = 갯수
string temp;
int ans = 0;

void input()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}
	cin >> temp;
	memset(dp, -1, sizeof(dp));

}

int dy[4] = { 1, 0 , -1 , 0 };
int dx[4] = { 0, 1 , 0 , -1 };

int dfs(int y, int x, int idx)
{
	// return  조건
	// idx가 temp길이보다 넘어가면?
	// -> temp 문자열을 만들 수 있으니까 
	if (idx >= temp.length())
		return 1;

	// 방문했으면(dp에 값이 채워져 있으면)
	if (dp[y][x][idx] != -1)
		return dp[y][x][idx];

	dp[y][x][idx] = 0;	// 방문처리겸 초기값 채우기
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			// k 보다 작을 때 까지 이동가능 (문제조건)
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;

			if (nx < 0 || ny < 0 || ny >= N || nx >= M)
				continue;
			if (arr[ny][nx] != temp[idx])	// 배열상 next가 다음 문자열이 아니면
				continue;

			dp[y][x][idx] = dp[y][x][idx] + dfs(ny, nx, idx + 1);
		}
	}
	return dp[y][x][idx];
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == temp[0])
				ans = ans + dfs(i, j, 1);
		}
	}

	cout << ans;
}



void print()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	input();
	solve();
	print();
}
