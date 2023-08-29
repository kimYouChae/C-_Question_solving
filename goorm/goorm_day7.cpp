
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M;
int arr[1001][1001];
int answer = 0;

int dx[] = { 0,1,1,1,0,-1,-1,-1 }; //7개의 좌표
int dy[] = { 1,1,0,-1,-1,-1,0,1 };

int check(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my < 0 || mx >= N || my >= N) //좌표를 벗어나면 끝내기 
		{
			continue;
		}

		if (arr[mx][my] == 1) // 주변의 칸이 구름 (1)이면
		{
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지 7
	cin >> N >> M;
	//입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j][i];
		}
	}
	//2중for문을 돌리면서 구름(1)이 아닌곳에 함수실행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] != 1)
			{
				int n = check(j, i);
				if (n == M)
				{
					answer++;
				}
			}
		}
	}
	cout << answer;

}






