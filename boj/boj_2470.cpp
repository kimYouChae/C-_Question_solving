
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
int arr[100001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void solve()
{
	sort(arr, arr + N);	// 정렬
	int start = 0;
	int end = N - 1;

	int min = 2000000000;

	int an1 = 0;
	int an2 = 0;
	while (true)
	{
		if (start >= end)
			break;

		int sum = arr[start] + arr[end];


		if (min > abs(sum))
		{
			min = abs(sum);
			an1 = arr[start];
			an2 = arr[end];

			if (sum == 0)
				break;
		}
		if (sum < 0)
			start++;
		else if (sum > 0)
			end--;
	}

	cout << an1 << " " << an2;


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
