
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
//정렬기준
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 1302
	map<string, int> ma;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		ma[str] ++; //find로 검사 안하고 value값 증가 시켜도 되나?
	}

	int result = 0;
	for (auto i = ma.begin(); i != ma.end(); i++)
	{
		result = max(result, i->second); //가장 큰 value 찾기
	}

	for (auto i = ma.begin(); i != ma.end(); i++)
	{
		// 가장 큰 value를 가진 key값 찾기
		if (result == i->second)
		{
			cout << i->first;
			break;
		}
	}
}
