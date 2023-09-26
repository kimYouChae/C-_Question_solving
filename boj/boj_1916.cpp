
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
int sNode, eNode;
const int MAX = 1001;
const int INF = 100000000;
vector<pair<int, int>> vec[MAX]; // vec[N]{} : N에 연결된 노드 , 가중치
int d[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 거리, 해당 노드

	pq.push({ 0,start }); // 시작 - 시작 거리는 0
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < vec[now].size(); i++) //현재 노드랑 연겯되어 있는 노드 탐색
		{
			int next = vec[now][i].first;
			int cost = dist + vec[now][i].second;

			// 현재 + 현재->다음 노드 까지 거리 vs d[next]에 저장되어 있는 최소거리
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

	//백준 1916
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e , w });
	}
	cin >> sNode >> eNode; //시작노드 , 도착 노드

	fill(d, d + MAX, INF); //최대값으로 채v워넣기
	dijkstra(sNode);

	// 저장된 최소 비용 출력
	cout << d[eNode];

}
