
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
#include<unordered_map>

int N, M, R, C;
int arr[1001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void solve()
{
	// 정렬
	sort(arr, arr + N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > sum + 1)
			//sum보다  + 1큰거는 sum이랑 연결 (누적합에서 바로 연결)되어 있어서 그런듯!
			break;
		sum += arr[i];
	}

	cout << sum + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	input();
	solve();

}
