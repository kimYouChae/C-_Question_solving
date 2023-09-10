
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
long long dp[81];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//น้มุ 13301
	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N + 1; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	long long answer = dp[N] * 2 + dp[N + 1] * 2;
	cout << answer;
}
