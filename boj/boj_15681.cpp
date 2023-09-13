
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

int N, M, Q;
const int MAX = 100001;
vector<int> vec[MAX];
int dp[MAX];
bool visit[MAX];

int dfs(int node) // 상위 노드를 들고옴 
{
	if (visit[node] == true)
	{
		return dp[node]; //만약에 방문 했으면 dp에 저장된거 return 
	}

	//방문 안 했으면?
	visit[node] = true; // 방문하면 true

	for (int next : vec[node]) //node에 연결되어 있는 수 탐색
	{
		if (visit[next] != true)
		{
			dp[node] = dp[node] + dfs(next); //dp[node]는 초기값 1
		}
	}

	//최종 dp의 node번째에 저장되어 있는거 출력
	return dp[node];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 
	cin >> N >> M >> Q;

	for (int i = 1; i < N; i++)
	{
		int s, e;
		cin >> s >> e;

		vec[s].push_back(e); //방향성이 x
		vec[e].push_back(s); // -> 그래서 양방향으로 연결?
	}

	//dp를 1로 초기화
	// memset으로 dp를 1로 초기화 하면 오류가 생길수도 있다!
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
	}

	dfs(M); //제일 상위 노드를 기준으로 dp를 채우기
	//입력
	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		cout << dp[q] << '\n';
	}

}
