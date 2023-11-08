
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
char arr[21][21];
bool alpha[27];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int answer = 0; // 최대 cnt를 구해야함

void dfs(int y, int x, int _cnt)
{
	//처음 0,0,0이 넘어왔을때 조건문에 걸리는걸 방지 하기위해서
	if (_cnt != 0)
	{
		// 방문 한 인덱스가 넘어오면 cnt 비교
		if (alpha[arr[y][x] - 'A'])
		{
			//cout << "( " << y << "," << x << " : " << _cnt << ")" << endl;
			//max 값 구하기
			if (_cnt > answer)
			{
				answer = _cnt;
			}

			//return을 여기서 해야함
			return;
		}

	}

	for (int i = 0; i < 4; i++)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		//my , mx가 배열을 넘어가는지 검사해야함
		if (my < 0 || mx < 0 || mx >= M || my >= N)
			continue;

		// 다음으로 갈 수 있으면
		// (F) -> D는 가능, {my,mx}가 F일때 F -> D -> F

		if (!alpha[arr[y][x] - 'A'])
		{
			alpha[arr[y][x] - 'A'] = true; // D를 방문처리
			dfs(my, mx, _cnt + 1); //다음 F를 넘김
			alpha[arr[y][x] - 'A'] = false; // D를 백트래킹 , 다시 D에서 출발할 수 잉ㅆ음
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	dfs(0, 0, 0);
	cout << answer;
}

