
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
const int MAX = 5001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // a에 저장된 노드 b,  가중치 c
int d[MAX];
bool visit[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //노드까지 최소거리 ,  현재 노드
	pq.push({ 0 , start }); // 첫번째 노드는 노드까지의 최소거리가 0
	d[start] = 0;
	visit[start] = true; //방문처리

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		visit[now] = true;

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first;
			int cost = vec[now][i].second + dist; // next 노드 까지의 거리

			if (!visit[next])
			{
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

	//백준 
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vec[a].push_back({ b,c }); //양방향 연결
		vec[b].push_back({ a,c });

	}
	int s, t;
	cin >> s >> t;

	fill(d, d + MAX, INF);
	dijkstra(s);
	cout << d[t];

}
