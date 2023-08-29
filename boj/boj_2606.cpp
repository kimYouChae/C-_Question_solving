
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

int N;
int M;
vector<int> vec[101];
int visit[101];

int answer = 0;
void dfs(int n)
{
	answer++;
	visit[n] = 1;

	for (int v : vec[n])
	{
		if (visit[v] == 0)
		{
			dfs(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// น้มุ 2606
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		vec[start].push_back(end);
		vec[end].push_back(start);
	}
	dfs(1);
	cout << answer - 1;
}






