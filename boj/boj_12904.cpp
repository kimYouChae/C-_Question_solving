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
int arr[20000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 12904
	string s;
	string t;

	cin >> s >> t;

	while (true)
	{
		if (t == s)
		{
			cout << 1 << endl;
			break;
		}

		if (t.length() < s.length())
		{
			cout << 0 << endl;
			break;
		}

		if (t[t.length() - 1] == 'B')  //B로 끝나면
		{
			t = t.substr(0, t.length() - 1); //ABB
			reverse(t.begin(), t.end()); // 문자열 뒤집기
		}

		else if (t[t.length() - 1] == 'A')
		{
			t = t.substr(0, t.length() - 1);
		}

		//cout << t << endl;
	}


}
