
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

	// 백준  
	while (true)
	{
		vector<int> vec;
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);

		sort(vec.begin(), vec.end());

		if (pow(vec[0], 2) + pow(vec[1], 2) == pow(vec[2], 2))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';

	}

}
