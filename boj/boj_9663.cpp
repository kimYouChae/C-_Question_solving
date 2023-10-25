
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
int _count = 0;
int board[15]; // i번째에는 몇번째 열에 퀸이 들어가 있는지 
//(퀸을 놓을 수 있는 열의 번호)  

bool promising(int cnt)  // 다음 퀸이 놓일수 있는 지 
{
	for (int i = 0; i < cnt; i++)
	{
		//같은 열이면 안됨 || 대각선이여도 안됨
		// 두 칸의 행의 차이 == 열의 차이가 같으면 대각선에 존재
		if (board[i] == board[cnt] || cnt - i == abs(board[cnt] - board[i]))
		{
			return false;
		}
	}
	return true;
}

void nqueen(int cnt) //cnt : 행이 몇번째 인지, 0~ N 까지 
{
	// 만약 cnt가 마지막 행까지 오면
	if (cnt == N)
	{
		// 0부터 N까지 퀸을 놓을수 있다!
		_count++;
		return;
	}

	//i : 몇번째 열인지 , 0 ~ N 까지
	for (int i = 0; i < N; i++)
	{
		board[cnt] = i; //cnt 행에 i번째 퀸을 놓음
		if (promising(cnt)) //cnt 행에 놓을수 잇으면, 
		{
			nqueen(cnt + 1); //다음행으로 넘어감
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
	cin >> N;
	nqueen(0);
	cout << _count;
}
