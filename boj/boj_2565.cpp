
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
#include<unordered_map>

int N, M, R, C;
int dp[101];
vector<pair<int, int>> vec;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int st, en;
		cin >> st >> en;
		vec.push_back({ st, en });
	}
}

void solve()
{
	// vec의 첫번쨰 pair로 정렬
	sort(vec.begin(), vec.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vec[i].second > vec[j].second)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		answer = max(dp[i], answer);	// '증가하는 부분수열'중에서 가장 큰거
	}

	cout << N - answer;
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

}
