
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

#define MAX 10001
#define INF 123456789

int N;
int M;
int coin[MAX];
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지 11일차
	cin >> N;
	for (int i = 0; i < 2; i++)
	{
		cin >> coin[i];
	}

	//최소값을 구하기 때문에 -> dp를 최대로 설정
	for (int i = 0; i <= N; i++)
	{
		dp[i] = INF;
	}

	dp[0] = 0;
	for (int i = 0; i < 2; i++)
	{
		// coin이 2,7 순서대로
		for (int j = coin[i]; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[N] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp[N];
	}

}






