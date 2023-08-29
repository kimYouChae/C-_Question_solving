
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
int arr[8];
bool visited[8];

void dfs(int depth)
{
	if (depth == M)  // depth가 ++ 되다가 정해진 길이가 되면 -> arr배열(순열 출력)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	//그게 아니면
	for (int i = 1; i <= N; i++) // 순열로 이루어 질수 있는건 1 ~ N의 수
	{
		if (!visited[i])
		{
			visited[i] = true; //방문처리
			arr[depth] = i; // 순열 arr배열에 수 넣기
			dfs(depth + 1);
			visited[i] = false; // 다시 되돌아오기 (백트래킹)

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 15619 -> dfs를 사용 (순열 / 백트래킹 방법)

	cin >> N >> M;
	dfs(0);

}





