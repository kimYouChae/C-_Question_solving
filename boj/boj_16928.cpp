
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
const int MAX = 101;
int load[MAX];
bool visit[MAX];

void input()
{
	cin >> N >> M;

	// 기본 load는 0
	memset(load, 0, sizeof(load));
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++)
	{
		// 사다리 입력
		// 시작보다 도착지가 더 큼
		int s, e;
		cin >> s >> e;
		load[s] = e;
	}
	for (int i = 0; i < M; i++)
	{
		// 뱀 입력
		// 시작보다 도착지가 작음
		int s, e;
		cin >> s >> e;
		load[s] = e;
	}
}

void solve()
{
	// bfs
	// 지금 있는 노드에서 load 의 값이 있으면 load따라서 bfs
	// 값이 없으면 주사위가 갈 수 있는 현재노드 + 1 ~ 현재노드 + 6 까지 bfs
	// 가장 먼저 100에 도착하면 return

	// qu에는 시작점, 몇번 연산햇는지
	queue<pair<int, int>> qu;
	qu.push({ 1 , 0 });	//1에서 시작

	while (!qu.empty())
	{
		int now = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		//cout << now << " / " << cnt << endl;
		// 100번째 칸에 도착했으면
		if (now == 100)
		{
			cout << cnt;
			return;
		}

		visit[now] = true;
		for (int i = 1; i <= 6; i++)
		{
			int nextnode = now + i;

			if (visit[nextnode])	//방문한 노드면? 건너뛰기
				continue;

			if (load[nextnode] == 0)	// 아무것도 없는 노드이면
			{
				qu.push({ nextnode , cnt + 1 });
			}
			else if (load[nextnode] != 0)	// 어디로 갈 수 있는 노드이면
			{
				qu.push({ load[nextnode], cnt + 1 });
			}
		}
	}

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
