
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
vector<int> A;
vector<int> B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// น้มุ 1026 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
	}

	sort(A.begin(), A.end(), greater<>());
	sort(B.begin(), B.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += A[i] * B[i];
	}
	cout << answer;
}
