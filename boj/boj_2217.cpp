
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
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준 2217
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

	sort(vec.begin(), vec.end());

	// N - 1까지
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int sum = vec[i] * (N - i);
		answer = max(answer, sum);

	}

	cout << answer;
}
