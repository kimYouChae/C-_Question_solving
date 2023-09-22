
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

int N, M, R, L;
int arr[51][51];
bool visit[51][51];
vector<pair<int, int>> vec;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int person = 0;
bool flag = true;
void bfs(int y, int x)
{
	queue<pair<int, int>> qu;
	qu.push({ y,x });
	visit[y][x] = true;

	while (!qu.empty())
	{
		int _y = qu.front().first;
		int _x = qu.front().second;

		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int my = _y + dy[i];
			int mx = _x + dx[i];

			if (mx < 0 || my < 0 || my >= N || mx >= N)
				continue;
			if (visit[my][mx])
				continue;

			if (abs(arr[_y][_x] - arr[my][mx]) >= L && abs(arr[_y][_x] - arr[my][mx]) <= R) // 두 인구의 차가 L이상 R 이하이면
			{
				person += arr[my][mx];
				vec.push_back({ my, mx });

				visit[my][mx] = true;
				qu.push({ my , mx });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준 16234
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	//BFS
	int answer = 0;

	while (flag)
	{
		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
				{
					vec.clear();
					vec.push_back({ i,j });
					person = arr[i][j]; // 들어가는 첫번째 좌표도 합치고 방문벡터에 넣어줘야함

					bfs(i, j);
				}

				if (vec.size() >= 2) // 연합이면
				{
					flag = true;
					for (int p = 0; p < vec.size(); p++)
					{
						arr[vec[p].first][vec[p].second] = person / vec.size();
					}

				}
			}
		}

		if (flag == true)
			answer++;
		memset(visit, false, sizeof(visit));


	}
	cout << answer;
}
