
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

int visit[100001];
int order = 1;

void bfs(int x)
{
	visit[x] = order;
	order += 1;
	queue<int> qu;
	qu.push(x);

	while (!qu.empty())
	{
		int _x = qu.front();
		qu.pop();

		for (int next : vec[_x])
		{
			if (visit[next] != 0)
				continue;

			qu.push(next);
			visit[next] = order;
			order += 1;

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

	bfs(R);
	for (int i = 1; i <= N; i++)
	{
		cout << visit[i] << '\n';
	}

}