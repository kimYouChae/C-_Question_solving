
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

bool comp(pair<string, int>& a, pair<string, int>& b) //pair형 vector 비교 (이젠 외울때가 되었다!
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
			return a.first < b.first; //사전순 
		return a.first.length() > b.first.length(); //문자열 길이 순 
	}
	return a.second > b.second; // 나온 횟수순
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 
	cin >> N >> M;

	map<string, int> m;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str.length() >= M) //조건에 맞으면
			m[str]++; //map의 key에 맞는 value값 증가
	}

	// map을 정렬 해야할 때! -> 보통 vector로 옮기고 , 정렬하는듯?
	vector<pair<string, int>> vec(m.begin(), m.end());
	// -> map의 begin부터 end까지 값을 vector에 '복사'함
	sort(vec.begin(), vec.end(), comp);

	for (auto p : vec)
		cout << p.first << '\n';

}
