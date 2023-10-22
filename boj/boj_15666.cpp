
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

int N, M;

int arr[10];
bool visit[10];
int input[10];

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	//중복되는 수열을 막으려면?
	int last = 0;

	for (int i = num; i <= N; i++)
	{
		if (input[i] != last)
		{
			//visit[i] = true;
			arr[cnt] = input[i];
			last = arr[cnt];
			dfs(i, cnt + 1);
			//visit[i] = false;

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준  

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
	}
	sort(input, input + N + 1);

	dfs(1, 0);
}
