
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	deque<int> de;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push_back")
		{
			int num;
			cin >> num;

			de.push_back(num);
		}
		else if (str == "push_front")
		{
			int num;
			cin >> num;

			de.push_front(num);
		}
		else if (str == "pop_front")
		{
			if (!de.empty())
			{
				cout << de.front() << '\n';
				de.pop_front();
			}
			else
			{
				cout << "-1" << '\n';

			}
		}
		else if (str == "pop_back")
		{
			if (!de.empty())
			{
				cout << de.back() << '\n';
				de.pop_back();
			}
			else
			{
				cout << "-1" << '\n';

			}
		}
		else if (str == "size")
		{
			cout << de.size() << '\n';
		}
		else if (str == "empty")
		{
			if (de.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front")
		{
			if (!de.empty())
			{
				cout << de.front() << '\n';
			}

			else
			{
				cout << -1 << '\n';
			}
		}
		else if (str == "back")
		{
			if (!de.empty())
			{
				cout << de.back() << '\n';
			}

			else
			{
				cout << -1 << '\n';
			}
		}


	}

}

