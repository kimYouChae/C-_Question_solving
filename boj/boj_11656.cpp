
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
vector<string> vec;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 14425
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i; i < str.length(); i++)
		{
			vec.push_back(str.substr(i));
		}
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}

}
