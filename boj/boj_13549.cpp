
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

const int MAX = 100001;
int visit[MAX];	// 시간초과 안나게 방문처리

int bfs_01(int start)
{
	// 걸리는 시간, 현재 거리
	// 제일 작은 시간을 출력 하는 거니까 
	// 작은 시간별로 정렬 -> 우선순위큐가 알아서 정렬 해줌
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	visit[start] = 1;

	// next 노드의 가중치가 0이면 front, 1이면 back
	while (!pq.empty())
	{
		int time = pq.top().first;	// 걸리는 시간
		int now = pq.top().second;	// 현재 위치
		pq.pop();

		//방문처리
		visit[now] = 1;

		// 목표 지점까지 왔을 때
		if (now == M)
			return time;

		//0초일때
		if (now * 2 < MAX && !visit[now * 2])
			pq.push({ time , now * 2 });

		// +1초일 때
		if (now + 1 < MAX && !visit[now + 1])
			pq.push({ time + 1 , now + 1 });

		// 1초 일 때 
		if (now - 1 >= 0 && !visit[now - 1])
			pq.push({ time + 1 , now - 1 });
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;
	cout << bfs_01(N);

}

