
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

	// 백준 
	cin >> N;

	int arr[101];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int cnt = 0;
	//점수를 "빼는것"만 가능하면 맨 끝에 있는게 가장 커야함
	for (int i = N - 1; i >= 0; i--)
	{
		while (arr[i] <= arr[i - 1])
		{
			cnt++;
			arr[i - 1] -= 1;
		}
	}

	cout << cnt;
}
