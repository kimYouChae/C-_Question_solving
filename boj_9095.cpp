
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
int dp[12];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 9095
	cin >> N;

	// 1을 만드는 경우의수 1
	// 2를 만드는 경우의수 2 (1+1,2)
	// 3을 만드는 경우의수 1+1+1, 1+2, 2+1,3
	// 4를 만드는 경우의수 1+1+1+1, 1+1+2, 1+2+1,2+1+1,2+2,3+1,1+3 

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		cout << dp[temp] << '\n';

	}
}



