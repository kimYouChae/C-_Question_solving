
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

	// 백준 2294 동전2
	// 이건 풀이 정리하기!
	cin >> N >> M;

	// dp 배열에 작은 동전부터 개수 갱신, 
	// 다음동전이랑 최솟값 저장
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i]; // 동전 담아놓는 배열
	}

	// 최소값을 구해야 하기 때문에
	for (int i = 0; i <= M; i++) {
		dp[i] = INF;
		//dp배열에 최댓값으로 설정
	}

	dp[0] = 0;
	// dp[n] = 합이 n인 동전 갯수
	for (int i = 0; i < N; i++) // 1 5 12
	{
		for (int j = coin[i]; j <= M; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			// 1일때는 처음부터~15
			// 5일때는 5~15
			// 12일때는 12~15
		}
	}

	if (dp[M] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp[M];
	}

}

