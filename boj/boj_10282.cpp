
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
const int MAX = 10001;
const int INF = 100000000;
int d[MAX];
vector<pair<int, int>> vec[MAX];
int cnt;
int answer;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 저장된 거리 , 노드에
	pq.push({ 0 , start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first; // 현재 노드에 연결된 다음노드
			int cost = dist + vec[now][i].second; // 다음 노드까지 가는 비용

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

	//백준 10282

	cin >> N;
	for (int i = 0; i < N; i++)
	{

		//d배열을 INF로 채우기
		fill(d, d + MAX, INF);
		cnt = 0;
		answer = 0;

		int n, dd, c; // 노드 갯수, 간선 갯수, 감염된 노드
		int a, b, s; // 시작, 도착노드 , 가중치
		cin >> n >> dd >> c;

		for (int j = 0; j < dd; j++)
		{
			cin >> a >> b >> s;

			vec[b].push_back({ a , s });
		}

		//다익스트라 실행
		dijkstra(c);

		// 최솟값 배열에 저장된 수 중에 가장큰수 -> 가장 멀리 있는 컴퓨터 (마지막 컴퓨터)
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == INF)
				continue;

			cnt++;
			if (d[i] > answer)
			{
				answer = d[i];
			}
		}

		cout << cnt << " " << answer << '\n';

		// 벡터 초기화
		for (int i = 0; i < MAX; i++) {
			vec[i].clear();
		}

	}



}
