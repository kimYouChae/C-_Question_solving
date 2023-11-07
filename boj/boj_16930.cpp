
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

#define INF 10000000
int N, M, R;
int arr[1001][1001];
int visit[1001][1001];
int xO, yO, xT, yT;
int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int cnt = 0;

void bfs(int y, int x)
{
	queue<pair<int, int>> qu;

	qu.push(make_pair(y, x));
	visit[y][x] = 1;

	while (!qu.empty())
	{

		int _y = qu.front().first;
		int _x = qu.front().second;
		qu.pop();

		if (_y == yT - 1 && _x == xT - 1)
			return;


		cout << "-----------" << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << visit[i][j] << " ";
			}
			cout << endl;
		}
		cout << "-----------" << endl;


		for (int i = 0; i < 4; i++)
		{
			//1부터 M 까지
			for (int j = 1; j <= R; j++)
			{
				int my = _y + (dy[i] * j);
				int mx = _x + (dx[i] * j);

				// 조건 검사
				if (mx < 0 || my < 0 || mx >= M || my >= N)
					break;
				if (arr[my][mx] == '#')
					break;

				//visit[][] = 0
				if (visit[my][mx] == 0)
				{
					visit[my][mx] = visit[_y][_x] + 1;
					qu.push({ my,mx });
				}
				else if (visit[my][mx] == visit[_y][_x] + 1) // 이건 왜 되는거징?
					continue;
				else
					break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	cin >> yO >> xO >> yT >> xT;

	bfs(yO - 1, xO - 1);
	cout << visit[yT - 1][xT - 1] - 1;
}

