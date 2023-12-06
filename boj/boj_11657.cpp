
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
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
vector<pair<int, pair<int, int >>> edges;
const int MAX = 501;
const int INF = 123456789;
long long d[MAX];	// 간선 최소값 저장 해놓는

bool bellmanFord(int start)
{
	d[start] = 0;	// 시작의 최소값은 항상 0

	// 1번부터 N번 노드 까지
	for (int i = 1; i <= N; i++)
	{
		// 모든 간선 확인
		// vector에 담긴 모든값 확인
		for (int j = 0; j < M; j++)
		{
			int from = edges[j].first;	// 시작점
			int to = edges[j].second.first;	// 도착점
			int cost = edges[j].second.second;	// 시작-도작점의 가중치

			// 예외처리 
			// 현재간선이 한번도 계산이 안되면
			if (d[from] == INF)
				continue;

			// 도착지점에 저장되어 있는 값 보다 
			// 출발지에서 도착지 까지 가는 값이 더 작으면 ? 
			if (d[to] > d[from] + cost)
			{
				d[to] = d[from] + cost;  //d 배열에 값 갱신

				// N번째에도 최단 거리가 갱신되면?
				// 음수사이클이 생김
				if (i == N)
					return true;
			}

		}
	}

	// 음수간선이 안 발생하면
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;	// 시작점, 도착점, 가중치

		edges.push_back({ a, {b,c} });
	}

	fill(d, d + MAX, INF);	// 최소값을 저장 해놓는 배열을 초기화

	bool negativeCycle = bellmanFord(1);	// 1번 도시에서 시작
	if (negativeCycle) // 음수 간선이 생기면
	{
		cout << -1 << '\n';
		return 0;
	}

	// 시작점(1번)을 제외한 
	// 다른 모든 노드로 가기 위한 최단거리 출력
	for (int i = 2; i <= N; i++)
	{
		if (d[i] == INF) // 연결이 안된 간선
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << d[i] << '\n';
		}

	}


}

