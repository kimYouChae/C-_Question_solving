
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
const int MAX = 50001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // 시작노드 -> 끝노드 ,  비용
int d[MAX];
bool visit[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 간선, 시작노드
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //비용
		int now = pq.top().second; //현재 노드
		pq.pop();

		if (dist < d[now])
			continue;

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first; //next 노드
			int cost = dist + vec[now][i].second; //next노드까지 가는 비용

			if (!visit[next]) //양방향 노드여서 방문 체크
			{
				visit[now] = true;
				if (cost < d[next])
				{
					d[next] = cost;
					pq.push({ cost, next });
				}

			}

		}


	}


}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 5972

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	fill(d, d + MAX, INF);
	dijkstra(1);

	cout << d[N];

}
