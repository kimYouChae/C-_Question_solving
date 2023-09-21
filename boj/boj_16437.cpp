
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
int animal[123457];
vector<long long> vec[123457];

bool visit[123457];

long long dfs(int node)
{
	//리프노드이면?
	if (vec[node].size() == 0) //연결은 단방향으로
	{
		if (animal[node] > 0)
			return animal[node];
		else if (animal[node] < 0)
			return 0;
	}

	long long rst = 0;
	for (int next : vec[node])
	{
		rst += dfs(next);
	}

	rst += animal[node];
	if (rst < 0)
		return 0;
	else
		return rst;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 16437
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		char ch;
		int many, node;
		cin >> ch >> many >> node;

		// i랑 node랑 연결 되어있음
		vec[node].push_back(i);

		if (ch == 'S') //양이면 양수
			animal[i] = many;
		else if (ch == 'W') //늑대면 음수
			animal[i] = many * (-1);
	}

	long long n = dfs(1);
	cout << n;
}
