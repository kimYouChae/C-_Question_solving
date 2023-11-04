
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

	string str;
	cin >> str;

	int arr[27];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < str.length(); i++)
	{
		// 대문자면?
		if (str[i] - 96 <= 0)
		{
			arr[str[i] - 'A'] += 1;
		}
		//소문자면
		else
		{
			arr[(str[i] - 32) - 'A'] += 1;
		}
	}

	int max = 0; //나온 횟수 저장
	char answer;
	for (int i = 0; i < 27; i++)
	{
		//값이 있을 때
		if (arr[i] != 0)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				answer = i + 'A';
			}

			else if (arr[i] == max)
				answer = '?';

		}
	}

	cout << answer;
}

