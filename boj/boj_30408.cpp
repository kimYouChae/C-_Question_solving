
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
map<int, int> ma;
bool flag = false;

// 춘배컴 30408 해결못함

void mm(int num)
{
	// 방문 처리를 map으로 하되,
	// bfs(queue)를 쓰면 편할 듯?

	queue<int> qu;
	qu.push(num);

	while (!qu.empty())
	{

		int n = qu.front();
		qu.pop();

		//cout << n << endl;

		if (ma.find(n) != ma.end())
		{
			continue;
		}
		ma[n] += 1; //방문 처리

		if (n == M)
		{
			cout << "YES";
			flag = true;
			exit(0);
		}
		if (n == 1 || n < M)
		{
			continue;
		}



		int a, b, c;

		if (n % 2 == 0)  //짝수
		{
			a = n / 2;
			if (ma.find(a) == ma.end())
			{
				qu.push(a);
			}

		}
		else if (n % 2 != 0) //홀수
		{
			b = (n - 1) / 2;
			c = ((n - 1) / 2) + 1;

			if (ma.find(b) == ma.end())
			{
				qu.push(b);
			}
			if (ma.find(c) == ma.end())
			{
				qu.push(c);
			}
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
	mm(N);

	if (!flag)
		cout << "NO";
}

