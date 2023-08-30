#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int result[51], arr[1000][1000];
bool visit[1000][1000];

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

void bfs(int y, int x, int num)
{
	int ret = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	ret++;
	visit[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + tmp.first;
			int nx = dx[i] + tmp.second;

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (arr[ny][nx] == num && !visit[ny][nx])
			{
				q.push(make_pair(ny, nx));
				visit[ny][nx] = true;
				ret++;
			}
		}
	}
	if (ret >= K)
		result[num]++;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				bfs(i, j, arr[i][j]);
			}
		}
	}

	int bigger = 0;
	int biggerIndex = 0;
	for (int i = 0; i < 51; i++)
	{
		if (result[i] == bigger) // 단지의 개수가 같으면
		{
			if (i > biggerIndex)
			{
				bigger = result[i];
				biggerIndex = i;
			}
		}
		else if (result[i] > bigger) // 단지의 개수가 더 크면
		{
			bigger = result[i];
			biggerIndex = i;
		}
	}

	cout << biggerIndex;
}