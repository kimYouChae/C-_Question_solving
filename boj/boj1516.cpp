
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
const int MAX = 501;
vector<int> vec[MAX];
int dp[MAX];
int enterance[MAX];
int cost[MAX];

void topologysort()
{
	queue<int> qu;

	// 진입 차수가 0 인거 넣기
	for (int i = 1; i <= N; i++)
	{
		if (enterance[i] == 0)
		{
			qu.push(i);
			dp[i] = cost[i];

		}
	}

	// 위상정렬, N번
	for (int i = 1; i <= N; i++)
	{
		int x = qu.front();
		qu.pop();

		for (int i = 0; i < vec[x].size(); i++)
		{
			int next = vec[x][i];
			enterance[next]--;

			dp[next] = max(dp[next], dp[x] + cost[next]);
			if (enterance[next] == 0)
			{
				qu.push(next);
			}

		}

	}

}


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
		cin >> cost[i];
		while (true)
		{
			int e;
			cin >> e;
			if (e == -1)
				break;

			vec[e].push_back(i);
			enterance[i]++;
		}
	}

	// 위상정렬
	topologysort();

	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << "\n";
	}

}

