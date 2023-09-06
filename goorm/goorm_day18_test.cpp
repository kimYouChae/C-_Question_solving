
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
const int MAX = 101;
int ud[MAX][MAX]; //  up , down배열
int rl[MAX][MAX]; // right, left 배열
int answer[MAX][MAX];

void getUd(int _y, int _x, char co) // 1부터 시작하는 2차원 배열
{
	if (co == 'U') // 위로 올라가면 y축 값이 작아짐
	{
		while (_y > 0) // _y가 0보다 클때 
		{
			ud[_y][_x] += 1; // 1더하기
			_y--;
		}
	}

	else if (co == 'D') //아래로 내려가면 y축 커짐
	{
		while (_y <= N) // _y가 0포함 클때
		{
			ud[_y][_x] += 1; // 1더하기
			_y++;
		}
	}
}

void getRl(int _y, int _x, char co)
{
	if (co == 'L') // 왼쪽으로 갈때 x축 작아짐
	{
		while (_x > 0) // 
		{
			rl[_y][_x] += 1; // 1더하기
			_x--;
		}
	}

	else if (co == 'R') // 오른쪽으로 갈때 x축 커짐
	{
		while (_x <= N) // 
		{
			rl[_y][_x] += 1; // 1더하기
			_x++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지
	cin >> N >> M;

	memset(ud, 0, sizeof(ud)); // 0으로 초기화
	memset(rl, 0, sizeof(rl));

	for (int i = 0; i < M; i++)
	{
		int y, x;
		char c;
		cin >> y >> x >> c;


		if (c == 'D' || c == 'U')
		{
			//위아래 배열에
			getUd(y, x, c);
		}
		else if (c == 'R' || c == 'L')
		{
			//좌우 배열에
			getRl(y, x, c);
		}

	}

	//배열 출력

	cout << "업다운" << endl;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << ud[i][j] << " ";
		}
		cout << endl;
	}

	cout << "좌우" << endl;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << rl[i][j] << " ";
		}
		cout << endl;
	}


	//answer배열 작성
	int answer = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (ud[i][j] != 0 && rl[i][j] != 0) // 둘다 숫자가 있을떄
			{
				answer += ud[i][j] * rl[i][j];
			}
		}
	}

	cout << answer;

}
