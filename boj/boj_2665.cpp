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

const int MAX = 51;
const int INF = 12345678;
int arr[MAX][MAX];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int dp[MAX][MAX];

void bfs_01()
{
	// 짧은 순 이면, 우선순위큐로 부수는벽이 젤 작은것(가중치)가 제일 작은 거 부터
	priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
	// 가중치 (부수는 벽의 갯수) , y좌표 x 좌표
	pq.push({ 0 , {0,0} });
	dp[0][0] = 0;	// 맨 처음 가중치는 0

	while (!pq.empty())
	{

		int breakWall = pq.top().first;	// 부순 벽의 갯수
		int nowY = pq.top().second.first;	//지금 y
		int nowX = pq.top().second.second;	// 지금 x
		pq.pop();

		// 상하좌우 4방향
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			// 범위 밖에 나가면
			if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= N)
				continue;

			// dp 배열 값 갱신
			// 최솟값을 구하는 거니까 dp에 저장 되어 있는 것 보다 크면 연산 x

			// dp 계산
			int nextDist = 0;
			if (arr[nextY][nextX] == 1)
				nextDist = 0;
			else if ((arr[nextY][nextX] == 0))
				nextDist = 1;

			if (dp[nextY][nextX] > dp[nowY][nowX] + nextDist)
			{
				dp[nextY][nextX] = dp[nowY][nowX] + nextDist;
				pq.push({ dp[nextY][nextX] , {nextY, nextX} });
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

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			char ch = str[j];
			arr[i][j] = ch - '0';
			dp[i][j] = INF;	// 일단 제일 큰 값으로
		}
	}

	bfs_01();
	cout << dp[N - 1][N - 1];
}

