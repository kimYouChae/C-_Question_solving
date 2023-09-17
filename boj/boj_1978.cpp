
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


int N, M, R;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 1978
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 1)
			continue;

		bool _is = true;
		for (int i = 2; i < temp - 1; i++)
		{
			// 나누어떨어지면?
			if (temp % i == 0)
			{
				_is = false;
				break;
			}
		}
		if (_is)
			cnt++;
	}

	cout << cnt;
}
