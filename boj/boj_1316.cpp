
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
int arr[101];
string str;

bool alpha[27];
int cnt = 0;

void check(string s)
{
	//첫번째는 방문처리
	alpha[s[0] - 'a'] = true;
	for (int i = 1; i < s.length(); i++)
	{
		//전 문자랑 같으면 -> 같은 문자는 넘어가기
		if (s[i] == s[i - 1])
			continue;

		//연속 x , 방문 0
		else if (s[i] != s[i - 1] && alpha[s[i] - 'a'])
		{
			cnt++;
			break;
		}

		//연속 x , 방문 x
		else
			alpha[s[i] - 'a'] = true;
	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기

	//백준  1136
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		memset(alpha, false, sizeof(alpha));
		check(str);
	}

	cout << N - cnt;
	// cnt는 그룹단어 x


}
