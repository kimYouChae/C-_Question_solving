
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
const int MAX = 10001;
vector<int> vec[MAX];
bool visit[MAX];

int ans;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		vec[e].push_back(s);
	}
}

void dfs(int s)
{
	ans++;
	cout << ans << endl;
	visit[s] = true;
	for (int i = 0; i < vec[s].size(); i++)
	{
		if (!visit[vec[s][i]])
			dfs(vec[s][i]);
	}
}

void solve()
{
	vector<pair<int, int >> ansV;
	int maxNum = 0;
	for (int i = 1; i <= N; i++)
	{
		dfs(i);
		ansV.push_back({ ans , i });	// 정답 vec에 담아놓기
		maxNum = (maxNum < ans) ? ans : maxNum;	// 최댓값 구하기

		// 초기화
		ans = 0;
		memset(visit, false, sizeof(visit));

	}

	// 최댓값 구하기
	for (int i = 0; i < ansV.size(); i++)
	{
		if (maxNum == ansV[i].first)
			cout << ansV[i].second << " ";
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
