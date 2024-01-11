
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
#include<unordered_map>

int N, M, R, C;
vector<pair<int, int  >> vec[100001];
int dis;
int u;	// 임의의 한 점 0 과 가장 긴 노드 u
bool visit[100001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e, d;
		cin >> s;

		while (true)
		{
			cin >> e;
			if (e == -1)
				break;
			cin >> d;

			vec[s].push_back({ e , d });	// 연결된 노드, 가중치
		}
	}
}

void dfs(int s, int w)	// 시작점, 가중치 
{

	if (visit[s])	// 양방향, 다음노드가 방문했으면 
		return;

	visit[s] = true;

	// 매번 계산할 때 마다 dis 초기화 -> 가능
	// 리프 노드일때만 계산해도 되지 않을까? -> 가능
	if (vec[s].size() == 1)
	{
		if (dis <= w)
		{
			u = s;
			dis = w;	// 더 큰 w의 값으로
		}
	}

	for (int i = 0; i < vec[s].size(); i++)
	{
		int next = vec[s][i].first;
		int nextDis = vec[s][i].second;

		dfs(next, w + nextDis);
	}


}


void solve()
{
	// 1. 임의의 한 점A을 잡아서 가장 멀리있는 노드B를 찾음
	// 2. 반환된 노드B를 기준으로 가장 멀리있는 노드C를 찾음
	// 3. B와 C의 거리가 트리의 지름

	dfs(1, 0);	// 임의의 한점 ( 여기서는 1로 고정 ), 가중치가 처음에는 0
	//1과 연결된 가장 멀리 있는 노드 u를 구함
	//cout << "u : " << u << endl;

	dis = 0;	//거리를 담아놓을
	memset(visit, false, sizeof(visit));	// visit 초기화

	dfs(u, 0);
	cout << dis;
}


void print()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	input();
	solve();
	print();
}
