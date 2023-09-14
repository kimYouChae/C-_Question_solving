
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
map<string, int> ma;
vector<string> vec;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 1764
	cin >> M >> N;
	for (int i = 0; i < N + M; i++)
	{
		string str;
		cin >> str;

		ma[str]++;
		//map의 key에 해당하는 value에 +1 

		if (ma[str] > 1) // map에 해당하는 key의 값이 1보다 크면 = 중복되면
		{
			vec.push_back(str);
		}
	}

	//사전순으로 출력
	sort(vec.begin(), vec.end());
	cout << vec.size() << '\n';
	for (string ss : vec)
	{
		cout << ss << '\n';
	}


}
