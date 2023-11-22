
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
const int MAX = 310;
int stair[MAX];
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 3] + stair[i] + stair[i - 1], dp[i - 2] + stair[i]);
	}
	cout << dp[N];




}

