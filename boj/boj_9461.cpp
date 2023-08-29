
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

int N;
int M;
long long dp[102];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// น้มุ 9461 c++
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 101; i++)
	{
		dp[i] = dp[i - 5] + dp[i - 1];
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		cout << dp[temp] << '\n';
	}

}





