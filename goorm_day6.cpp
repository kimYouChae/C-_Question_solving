
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M = 3;
string str;
vector<char> vec; // 기본 벡터
vector<tuple<string, string, string>> strvec;
set<string> s;

int getIter(string abc)
{
	int position = 0;
	auto iter = s.find(abc);
	if (iter != s.end()) {
		position = distance(s.begin(), iter);
	}
	return position;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 6일차 구름톤 챌린지
	// 길이가 n개인 문자열을 r로 나누는 경우의 수는?

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		vec.push_back(str[i]);
	}

	//나눠진 문자열을 무조건 3개 -> 문제조건

	string start = "";

	for (int i = 0; i < N; i++)
	{

		start += vec[i];

		//cout << "start : " << start;
		string mid = "";
		string end = "";

		for (int j = i + 1; j < N - 1; j++)
		{
			mid += vec[j];
			end = str.substr(j + 1);

			//cout << " mid / end : " << mid << " " << end;

			strvec.push_back(make_tuple(start, mid, end));
			s.insert(start);
			s.insert(mid);
			s.insert(end);
		}
		//cout << endl;
	}

	/*
	cout << "---중복제거---" << endl; //set으로 중복제거
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}*/


	// 합 찾기
	//cout << "--합 찾기 ---" << endl;
	int score = 0;
	for (int i = 0; i < strvec.size(); i++)
	{
		//a,b,cd
		//getIter 문자열이 set에서 몇번째인지 반환
		int n1 = getIter(get<0>(strvec[i])) + 1;
		int n2 = getIter(get<1>(strvec[i])) + 1;
		int n3 = getIter(get<2>(strvec[i])) + 1;
		int sum = n1 + n2 + n3;

		//cout << "sum : " << sum << endl;
		score = max(score, sum);

	}
	cout << score;

}






