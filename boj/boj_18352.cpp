
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

int N, M, S;
int K; //거리가 K인 도시
const int MAX = 300001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX];
int d[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0 , start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int cost = dist + vec[now][i].second;

			if (cost < d[next])
			{
				d[next] = cost;
				pq.push({ cost, next });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 
	cin >> N >> M >> K >> S;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back({ b,1 }); // 두 노드 사이의 거리는 1
	}

	fill(d, d + MAX, INF);
	dijkstra(S);

	vector<int> answer;
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == K)
			answer.push_back(i);
	}

	if (answer.size() == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << '\n';
		}
	}



}
