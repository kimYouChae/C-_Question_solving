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
const int MAX = 101;
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0 ,1, 0, -1 };

void bfs()
{
	fill(visit[0], visit[MAX - 1], false);

	queue<pair<int, int>> qu;
	qu.push({ 0,0 });
	visit[0][0] = true;

	while (!qu.empty())
	{
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (visit[ny][nx])
				continue;

			// 방문처리
			visit[ny][nx] = true;

			// 만약 1 이면? -> 0으로 바꾸기
			if (arr[ny][nx] == 1)
			{
				arr[ny][nx] = 0;
				continue;
			}

			// 만약 0 이면? -> 공기가 퍼짐
			else if (arr[ny][nx] == 0)
			{
				qu.push({ ny, nx });
			}
		}
	}

}

int countCheese()
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
				count++;
		}
	}

	return count;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> vec; // 치즈가 몇개 남았는지 저장해놓을 
	vec.push_back(0);	// 첫번째 아무수나 넣어놓기
	int answer = 0;
	while (true)
	{
		int left = countCheese();	// 남은 치즈갯수
		if (left == 0)
			break;

		answer++;	// 몇시간 지났는지
		bfs();		// bfs
		vec.push_back(left);
	}

	cout << answer << '\n';
	cout << vec[vec.size() - 1];

}

