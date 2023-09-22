
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

int N, M, R;
vector<int> vec[100001];

bool visit[100001];
int order = 1;
int answer[100001];
void dfs(int x)
{
	visit[x] = true;
	answer[x] = order;
	order += 1;

	for (int next : vec[x])
	{
		if (!visit[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		vec[s].push_back(e);
		vec[e].push_back(s);
	}

	//작은 수 부터 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(vec[i].begin(), vec[i].end(), greater<>());
	}

	dfs(R);
	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << '\n';
	}

}
