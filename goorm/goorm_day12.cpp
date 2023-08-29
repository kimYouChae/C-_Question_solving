
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
int arr[1001][1001];
int cnt = 0;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
queue<pair<int, int>> q;

void bfs(int _x, int _y)
{
	pair<int, int> p = make_pair(_x, _y);
	q.push(p);

	while (!q.empty())
	{
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int mx = _x + dx[i];
			int my = _y + dy[i];

			if (mx < 0 || my < 0 || mx >= N || my >= N)
			{
				continue;
			}
			if (arr[mx][my] == 0) // 문제조건 -> 0이면 설치x
			{
				continue;
			}

			arr[mx][my] = 0;
			q.push(make_pair(mx, my));
		}
	}



}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j][i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] == 1)
			{
				cnt++;
				bfs(j, i);
			}
		}
	}
	cout << cnt;
}
