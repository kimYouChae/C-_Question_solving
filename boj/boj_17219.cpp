
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
map<string, string> ma;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준  
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string id, pw;
		cin >> id >> pw;

		ma.insert({ id, pw });
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (ma.find(str) != ma.end())
		{
			cout << ma[str] << '\n';
		}
	}

}
