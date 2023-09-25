
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
int s;

const int MAX = 20001;
const int INF = 100000001;
vector<pair<int, int>> vec[MAX];
int d[100001]; // 최단 거리 테이블

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 거리 , 노드 인덱스 (작은 순으로 하기 위해서 vector<자료형> , greater<자료형> 넣어줌)
	pq.push({ 0 , start }); // 출발 - 출발 거리는  0
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //현재 노드 까지의 비용
		int now = pq.top().second; //현재 노드
		pq.pop();

		//이미 최단 경로 이면? (저장 되어 있는 경로 < 현재 경로 -> 최소 경로가 계산되어있음)
		if (d[now] < dist)
			continue;

		for (int i = 0; i < vec[now].size(); i++) // 현재 연결된  노드 탐색
		{
			int next = vec[now][i].first;
			// 현재 거리 + 연결 되어 있는 노드의 거리
			int cost = dist + vec[now][i].second; // 거쳐서 가는 노드의 비용 
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

	//백준 1753

	cin >> N >> M >> s; // 노드 갯수, 간선 갯수, 시작 노드
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e, w }); // 시작 노드 -> 끝노드 ,  가중치
	}

	// 최단 거리 테이블을 INF 값으로 초기화 
	// 최소값을 구해야 하기 때문)
	fill(d, d + 100001, INF);

	// 다익스트라 알고리즘 수행
	dijkstra(s);

	for (int i = 1; i <= N; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';

	}

}
