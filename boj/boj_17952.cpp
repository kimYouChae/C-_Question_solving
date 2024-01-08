
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
#include<unordered_map>

int N, M, R, C;
stack<pair<int, int>> st;

void input()
{
	cin >> N;
}

void solve()
{
	int answer = 0;
	stack<pair<int, int>> st;

	for (int i = 0; i < N; i++)
	{
		int is;
		cin >> is;

		if (is == 1)	// 1일때 입력, 0이면 패스
		{
			int a, b;
			cin >> a >> b;
			st.push({ a, b });	//점수, 소요시간
		}
		if (!st.empty())
		{
			st.top().second--; // 처음에 입력된 소요시간 --
			if (st.top().second == 0)	// 소요시간이 0이면
			{
				answer += st.top().first; // 점수더하기
				st.pop();
			}
		}
	}
	cout << answer;

}

void print()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	input();
	solve();
	print();
}
