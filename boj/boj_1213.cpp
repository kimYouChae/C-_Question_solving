
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
int arr[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 1213 c++
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		arr[str[i] - 'A'] += 1;
	}

	//검사
	int cnt = 0;

	for (int i = 0; i < 27; i++)
	{
		if (arr[i] % 2 == 1) //알파벳의 갯수가 홀수인
		{
			cnt++;
		}

	}

	string ans = "";
	//알파멧의 갯수가 홀수인게 두개 이상 존재한다면
	if (cnt >= 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else  //펠린드룸 구하기
	{
		// 지금 까지 나온 알파벳의 갯수/2를 더함
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				ans += i + 'A';
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] % 2)
				ans += i + 'A';
		}

		for (int i = 26; i >= 0; i--)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				ans += i + 'A';
			}
		}
	}
	cout << ans;

}
