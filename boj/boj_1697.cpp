
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
const int MAX = 1000002;
int visit[MAX];
queue<pair<int, int>> qu;

void find(int num, int cnt)
{
	qu.push(make_pair(num, cnt));

	while (!qu.empty())
	{
		int now = qu.front().first;
		int dep = qu.front().second;
		visit[now] = true;

		qu.pop();

		if (now == M)
		{
			cout << dep;
			break;
		}

		// 방문한 숫자가 아니고
		// 입력받은 M + 1보다 작을 때

		if (now - 1 >= 0 && now - 1 < MAX && !visit[now - 1])
		{
			qu.push(make_pair(now - 1, dep + 1));
		}
		if (now + 1 >= 0 && now + 1 < MAX && !visit[now + 1])
		{
			qu.push(make_pair(now + 1, dep + 1));
		}
		if (now * 2 >= 0 && now * 2 < MAX && !visit[now * 2])
		{
			qu.push(make_pair(now * 2, dep + 1));
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
	find(N, 0);

}
