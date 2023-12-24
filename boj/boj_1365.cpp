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
const int MAX = 100001;
int arr[MAX];
vector<int> vec;

int lowerBound(int num)
{
	int start = 0;
	int end = vec.size() - 1;
	int mid;
	while (true)
	{
		mid = (start + end) / 2;
		if (start >= end)
			break;
		if (vec[mid] > num)
			end = mid;
		else if (vec[mid] < num)
			start = mid + 1;
	}
	return end;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N;
	//LIS를 돌기위해 N 번만큼 연산
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		// 벡터가 비어있으면 그냥 넣는다
		if (vec.size() == 0)
			vec.push_back(num);

		// arr의 값이 vec의 마지막 값보다 작으면
		// -> lower bound의 자리에 넣어준다
		else if (num < vec[vec.size() - 1])
		{
			int lower = lowerBound(num);	// lower_bound() 함수가 있지만 직접 구현 해보자
			vec[lower] = num;
		}

		// vec의 마지막 값보다 더 크면 
		// -> 그냥 뒤에 추가
		else if (num >= vec[vec.size() - 1])
			vec.push_back(num);
	}

	cout << N - vec.size();
}
