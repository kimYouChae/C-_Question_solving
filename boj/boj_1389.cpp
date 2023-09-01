
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
int INF = 1000000000;
int arr[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 1389
	cin >> N >> M;

	//memset(arr, INF, sizeof(arr)); 2차원배열은 사용하면 적용안됨
	//초기배열 입력
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;

	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else if (i != j && arr[i][j] != 1)
			{
				arr[i][j] = INF;
			}
		}

	}

	// 출발 -> 도착 바로 가는 비용 (vs) 출발 ->중간노드 + 중간노드 -> 도착노드로 가는 비용
	// 최소비용을 arr에 저장
	//k  거쳐가는 노드
	for (int k = 1; k <= N; k++)
	{
		// i 출발노드
		for (int i = 1; i <= N; i++)
		{
			// j 도착노드
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// arr배열에 저장된 값이 제일 작은사람
	int val = 1000000000;
	int idx = 0;

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		//i에서 출발해서 각각 도착지에(1부터 5까지)가는 수를 더하기
		for (int j = 1; j <= N; j++)
		{
			temp += arr[i][j];
		}

		if (temp < val)
		{
			val = temp;
			idx = i;
		}
	}

	cout << idx;
}
