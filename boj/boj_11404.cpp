
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
int arr[101][101];
int MAX = 987654321;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 11404

	cin >> N >> M;

	//MAX와 0 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = MAX;
			}
		}
	}

	//값 입력
	for (int i = 0; i < M; i++)
	{
		int s, e, w;

		cin >> s >> e >> w;
		arr[s][e] = min(arr[s][e], w);
	}

	//플로이드 워셜
	// K : 중간 위치
	for (int k = 1; k <= N; k++)
	{
		// i : 시작위치
		for (int i = 1; i <= N; i++)
		{
			// j : 도착위치
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	//출력
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == MAX)
			{
				cout << 0 << " ";
				continue;
			}
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}
