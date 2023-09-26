
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
const int INF = 100000000;
const int MAX = 1010;
vector<pair<int, int>> vec[MAX];
int d[MAX];
int r[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리 ,  현재노드
	pq.push({ 0 ,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //현재 노드까지의 거리
		int now = pq.top().second; //현재 노드
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++) // 현재 노드랑 연결된 노드 탐색 
		{
			int next = vec[now][i].first; //다음노드
			int cost = dist + vec[now][i].second; //현재 노드까지의 거리 + 다음 노드까지 가는 거리

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

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e,w });
	}

	// 모든 노드에서 start로 가는 경로값 
	for (int i = 1; i <= N; i++)
	{
		fill(d, d + MAX, INF);
		dijkstra(i); // 1부터 4 까지,모든 경로를 구하기
		r[i] = d[S];
		// r배열에는 도착지점까지 가는 최소비용 저장
	}

	fill(d, d + MAX, INF);
	dijkstra(S); // 시작 노ㄱ드부터 끝 노드 까지 가는 경로를 d에 저장

	for (int i = 1; i <= N; i++)
	{
		r[i] = r[i] + d[i];
	}
	sort(r + 1, r + N + 1);
	int answer = r[N];

	cout << answer;


}
