
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
vector<int> vec[2001];
bool visit[2001];
bool flag = false;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		vec[s].push_back(e);
		vec[e].push_back(s);
	}
}

void dfs(int s, int d)	// 시작노드 , 깊이 
{
	if (d == 5)
	{
		flag = true;
		return;
	}

	for (int i = 0; i < vec[s].size(); i++)
	{
		// 만약에 다음 노드가 방문했으면 1->7->1일 경우
		if (visit[vec[s][i]])
			continue;

		// 백트래킹 하는 부분 -> 순서 상관 있음 !! 
		visit[s] = true;
		dfs(vec[s][i], d + 1);		// 다음 노드를 dfs로 넣기
		visit[s] = false;	// 다시 돌아오면 false로
	}
}

void solve()
{
	// 0부터 N 까지 한번씩 돌아야함
	for (int i = 0; i < N; i++)
	{
		dfs(i, 1);
		if (flag)
		{
			cout << 1;
			return;
		}
	}
	cout << 0;

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
