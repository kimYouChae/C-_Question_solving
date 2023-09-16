
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
const int MAX = 10002;
int money[MAX];
int parent[MAX];
bool visit[MAX];


int getParent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y)
{
	x = getParent(x);
	y = getParent(y);

	//돈을 기준으로 union
	if (money[x] >= money[y])
		parent[x] = y;
	else
		parent[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 16562
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
	{
		cin >> money[i];
	}

	//parent를 자기자신으로 채워놔야 한다
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	//입력, 합치기
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b); //합치기
	}

	/*
	//N의 수 만큼 (학생의 수 만큼)
	int arr[MAX]; // 최소값이 들어가있는
	for (int i = 1; i <= N; i++)
	{
		arr[i] = moneyMAX;
	}

	// 부모와 그 자식이 가지고 있는 돈을 비교해서 더 작은값을 arr에 저장
	for (int i = 1; i <= N; i++)
	{
		arr[parent[i]] = min(arr[parent[i]], money[i] );
	}

	// moneyMAX 가 아니면 ? -> 최소값을 가지고 있음 그거만 answer에 더함
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] != moneyMAX)
		{
			answer += arr[i];
		}
	}
	*/
	long long answer = 0;
	for (int i = 0; i <= N; i++)
	{
		int cur = getParent(i);
		if (!visit[cur])
		{
			answer += money[cur];
			visit[cur] = true;
		}
	}


	//가지고 있는 돈 이하면
	if (answer <= R)
		cout << answer;
	else // 내 돈보다 많으면
		cout << "Oh no";
}
