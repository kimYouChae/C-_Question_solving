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
int arr[9];
bool visit[9];
void dfs(int cnt) // num : 이 수 보다는 커야함 , cnt : arr안에 채워진 수의 갯수
{
	if (cnt == M)
	{
		//M-1까지 arr 출력
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;

	}

	for (int i = 1; i <= N; i++) // num 보다는 커야함 
	{
		//visit[i] = true;
		arr[cnt] = i;
		dfs(cnt + 1);
		//visit[i] = false;
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
	dfs(0);


}
