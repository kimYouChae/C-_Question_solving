
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

int N;
int M;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 1931
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int f, e;
		cin >> f >> e;
		vec.push_back(make_pair(e, f));
	}

	sort(vec.begin(), vec.end()); // 첫번째 int기준으로 sort

	int cnt = 1;
	int first = vec[0].first;
	int end;

	for (int i = 1; i < N; i++)
	{
		if (first <= vec[i].second)
		{
			cnt++;
			first = vec[i].first;
			//cout << i << "번째 / " << first << endl;;
		}
	}

	cout << cnt;
}






