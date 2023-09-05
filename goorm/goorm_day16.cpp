
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
int arr[2004][2004];
vector<int> vec[2004];
int visit[2004];

void bfs(int _n)
{
	queue<int> qu;
	qu.push(_n);

	visit[_n] = 1; //방문하면 1

	while (!qu.empty())
	{
		int mx = qu.front();
		qu.pop();

		for (int next : vec[mx]) // _n에 연결되어 있던 
		{
			if (visit[next] == 1) //방문했으면 
			{
				continue;
			}
			visit[next] = 1; //방문처리
			qu.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (arr[i][j] && arr[j][i]) //값이 두군데 다 존재하면 -> 서로 연결되어 잇는거
			{
				vec[i].push_back(j);
				vec[j].push_back(i);
			}

		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] != 1) // 방문 안 했으면
		{
			ans++;
			bfs(i);
		}
	}

	cout << ans;
}
