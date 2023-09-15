
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



int N, M, R;
const int MAX = 101;
const int INF = 1000000000;
int pro[MAX][MAX]; //플로이드 워셜 배열
int weapon[MAX]; // 해당 지역에 해당되는 무기갯수

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 14938
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
	{
		cin >> weapon[i];
		// 지역은 1~N개 존재
	}

	//먼져 INF 값으로 채워넣어야함
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j)
				pro[i][j] = 1;
			else
				pro[i][j] = INF;
		}
	}

	//입력
	for (int i = 1; i <= R; i++)
	{
		int s, e, weight;
		cin >> s >> e >> weight;

		//양방향 통행이 가능하니까 
		//end -> start연결
		pro[s][e] = weight;
		pro[e][s] = weight;
	}


	//플로이드 워셜
	// p : 거쳐가는 중간지점
	for (int p = 1; p <= N; p++)
	{
		//i : 시작
		for (int i = 1; i <= N; i++)
		{
			// j : 끝
			for (int j = 1; j <= N; j++)
			{

				// i->j에서 직접 가는거 vs i->p 에서 p->j로 가는거 최솟값
				if (pro[i][j] > pro[i][p] + pro[p][j])
				{
					pro[i][j] = pro[i][p] + pro[p][j];
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = weapon[i];  // 시작지점 아이템 파밍
		for (int j = 1; j <= N; j++)
		{
			// 그 경로가 수색범위 보다 낮을떄
			if (pro[i][j] <= M && i != j)
			{
				cnt += weapon[j];
			}
		}
		answer = max(cnt, answer);
	}

	cout << answer;
}
