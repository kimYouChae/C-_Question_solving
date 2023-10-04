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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 
	string a, b;
	cin >> a >> b;

	int answer = 100000000;
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		int cnt = 0;
		string bs = b.substr(i, a.length()); // i 부터 짧은 문자열 a만큼 b 자르기
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] != bs[j])
				cnt++;
		}

		answer = min(answer, cnt);
	}
	cout << answer;
}
