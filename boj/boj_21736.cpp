
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
char arr[601][601];
int visit[601][601];
int answer = 0;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visit[x][y] = 1; //방문했으면 1

	if (arr[x][y] == 'P')
	{
		answer += 1;
	}

	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my < 0 || mx >= M || my >= N)
		{
			continue;
		}
		if (visit[mx][my] != 0)
		{
			continue;
		}
		if (arr[mx][my] == 'X' || arr[mx][my] == 'I') // x이면 더 못감
		{
			continue;
		}
		dfs(mx, my);

	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 21736
	cin >> N >> M;

	int ix = 0;
	int iy = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			char ch = str[j];
			arr[j][i] = ch;

			if (ch == 'I')
			{
				ix = j;
				iy = i;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	//cout << ix << " , " << iy << endl;
	dfs(ix, iy);
	if (answer == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << answer;
	}
}
