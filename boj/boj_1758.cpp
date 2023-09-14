
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

long long N;
vector<long long> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//น้มุ 1758
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;

		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), greater<>());

	long long answer = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int tip = vec[i] - (i + 1 - 1);

		if (tip >= 0)
		{
			answer += tip;
		}

	}
	cout << answer;
}
