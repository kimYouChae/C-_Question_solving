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
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());

	int answer = 0;
	int start = 0;
	int end = N - 1;
	while (true)
	{
		//cout << start << " / " << end << endl;
		if (start >= end)
			break;

		if (vec[start] + vec[end] == M)
		{
			start += 1; end -= 1; answer++;
		}
		else if (vec[start] + vec[end] < M)
			start += 1;
		else if (vec[start] + vec[end] > M)
			end -= 1;

	}
	cout << answer;
}

