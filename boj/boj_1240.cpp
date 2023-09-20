
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
vector<pair<int, int>> vec[1001];

int visit[1001];
int bfs(int a, int b) // 출발, 도착 노드 번호
{
	visit[a] = 0;
	queue<int> qu;
	qu.push(a);

	while (!qu.empty())
	{
		int ma = qu.front();
		qu.pop();

		for (auto next : vec[ma]) // ma에 연결된 {2,1} pair형 next
		{
			if (visit[next.first] >= 0) //방문했으면
				continue;

			qu.push(next.first);
			visit[next.first] = visit[ma] + next.second;
		}

	}
	return visit[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 1240
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int s, e, w;;
		cin >> s >> e >> w;

		vec[s].push_back({ e,w });
		vec[e].push_back({ s,w });
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		memset(visit, -1, sizeof(visit));
		int an = bfs(start, end);
		cout << an << '\n';
	}

}
