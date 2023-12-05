/*
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
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
	// 가희와 함께하는 6회 코딩테스트

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	// 17등~20등까지
	set<int> s;

	cin >> N;
	cin >> M;
	for (int i = 0; i < N - 1; i++)
	{
		int num;
		cin >> num;

		s.insert(num);
	}

	int idx = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		if (*iter >= M)
		{
			break;
		}
		else
		{
			idx++;
		}
	}

	cout << N - idx;


}

*/