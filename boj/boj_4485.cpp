
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

int N, M, R;
int X, Y;
const int MAX = 126;
const int INF = 12345678;

int arr[MAX][MAX];
int d[MAX][MAX];	// 최소 거리를 담아놓는

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//bfs를 기준으로 다엑스트라
void Bfs_Dijkstra(int y, int x)
{
	// 다엑스트라 우선순위큐
	priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>>> > pq;
	pq.push({ arr[y][x] , {y , x} });
	// 거리 , {y좌표 , x 좌표}
	d[y][x] = arr[y][x];
	// 처음 - 거리

	while (!pq.empty())
	{
		// 현재 노드
		int dist = pq.top().first;	// 현재까지 거리
		int nowY = pq.top().second.first;	// 현재 노드 Y
		int nowX = pq.top().second.second;	// 현재 노드 X
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];	// 다음 y좌표
			int nextX = nowX + dx[i];	// 다음 x 좌표

			// 다음좌표가 배열 넘어가면 안됨
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				continue;

			int nextdist = dist + arr[nextY][nextX];

			if (nextdist < d[nextY][nextX])
			{
				// 거리 갱신
				d[nextY][nextX] = nextdist;	//더 짧은걸로 갱신

				// 우선순위 큐에 거리와 현재 노드 넣기
				pq.push({ nextdist, { nextY , nextX } });
			}
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	int idx = 1;
	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		// 초기화
		fill(arr[0], arr[MAX - 1], 0);
		fill(d[0], d[MAX - 1], 0);

		//입력
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		// 최대값으로 미리 채워놈
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				d[i][j] = INF;
			}
		}

		Bfs_Dijkstra(0, 0); // 시작점

		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << "Problem " << idx << ": " << d[N - 1][N - 1] << '\n';
		idx++;
	}

}

