
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

int N, M, R, C;
const int MAX = 100001;
vector<int> vec[MAX];
int dp[MAX];

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		if (temp == -1)
			continue;

		vec[temp].push_back(i);	// temp가 부모, i가 본인 (자식)
	}
}

void dfs(int s)
{
	for (int i = 0; i < vec[s].size(); i++)
	{
		dp[vec[s][i]] += dp[s];
		dfs(vec[s][i]);
	}
}

void solve()
{
	fill(dp, dp + MAX, 0);	//-1로 채워 넣기
	for (int i = 0; i < M; i++)
	{
		int s, cost;
		cin >> s >> cost;

		dp[s] += cost;
		//cout << n << endl;
	}

	dfs(1);	//시작이 1

	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << " ";
	}
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
