
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


int N, M, R;
int arr[100001];
int answer[100001];

void binarySearch(int target) //이분탐색
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == target)
		{
			cout << 1 << '\n';
			return;
		}

		// 값이 작다면?
		if (target < arr[mid])
		{
			right = mid - 1;
		}
		//값이 크다면?
		else if (target > arr[mid])
		{
			left = mid + 1;
		}
	}

	//만약검색되지 안았다면
	cout << 0 << '\n';
	return;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 1920 이분탐색 사용
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//이분탐색을 하기 위해서는 sort해야한다!
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		binarySearch(a);
	}



}
