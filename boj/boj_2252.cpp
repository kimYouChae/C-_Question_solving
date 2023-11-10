
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
vector<int> vec[32001]; // 연결 구조 
int enterance[32001]; // 진입 차수

int answer[32001];
void topologySort()
{
	queue<int> qu;

	// 시작점 (초기값) 넣기
	// 진입차수가 0인 노드를 큐에 삽입
	// vec에 연결 되어 있는게 1 ~ N 까지 수여서 for문으로 비교 하는듯!
	for (int i = 1; i <= N; i++)
	{
		if (enterance[i] == 0)
			qu.push(i);
	}

	// 위상 정렬이 되려면 N 개의 노드를 방문 해야함
	for (int i = 1; i <= N; i++)
	{
		// N 개의 노드를 방문하기 전에 qu가 비면?
		// = 사이클이 발생, 위상정렬 불가능
		if (qu.empty())
			return; // 함수 빠져나가기

		int x = qu.front();
		qu.pop();
		answer[i] = x; // 위상정렬의 정답은 qu에서 꺼낸 순서, 나온 순서대로 정답 배열에 넣어줌

		// x에 연결 되어있는 노드 탐색, 진입차수 하나씩 줄이기 
		// 간선 연결을 해제함
		for (int i = 0; i < vec[x].size(); i++)
		{
			// 만약 간선 연결을 해제 했는데( -- ), 진입차수가 0이 되면
			// 큐에 넣기
			if (--enterance[vec[x][i]] == 0)
				qu.push(vec[x][i]);

		}
	}

	// 위상 정렬 후
	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] << " ";
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
	for (int i = 0; i < M; i++)
	{
		int f, e;
		cin >> f >> e;
		vec[f].push_back(e); // 1에 3이 연결 되어 있음
		++enterance[e];
		// 시작점은 진입차수가 0 (시작점으로 아무것도 안들어와서 0)
	}

	topologySort();
}

