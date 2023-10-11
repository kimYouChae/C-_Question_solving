
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

int N, M, S;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준 1343
	string str;
	cin >> str;

	int cnt = 0;
	string answer = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'X')
			cnt++;
		if (str[i] == '.')
		{
			answer += '.';
			if (cnt % 2 != 0) //2로 안나누어 지면 -> AAAA와 BB로 못만듬
				break;
			else
				cnt = 0;
		}

		//문자열 검사 -> 매 문자 마다 검사!
		// BB다음에 XX가 오면 BB+BB가 아니라 AAAA 여서 다음 문자 검사하는듯!
		if (cnt == 2 && str[i + 1] != 'X')
		{
			answer += "BB";
			cnt = 0;
		}
		else if (cnt == 4)
		{
			answer += "AAAA";
			cnt = 0;
		}

	}

	if (cnt % 2 != 0)
		cout << -1;
	else
		cout << answer;
}
