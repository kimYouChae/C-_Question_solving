
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
vector<int> vec;	//LIS를 담아 놓는
int arr[40010];

int lowerBound(int n)
{
	int start = 0;
	int end = vec.size() - 1;

	while (true)	// start가 end 보다 커지면 중지 
	{
		int mid = (start + end) / 2;

		if (start >= end)
			break;

		if (vec[mid] > n)
			end = mid;
		else if (mid < n)
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

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		int temp;
		temp = arr[i];

		// vec가 비어있을 땐 그냥 추가
		if (vec.size() == 0)
			vec.push_back(temp);
		// 마지막 수 보다 temp가 더 크면 , 그냥 추가
		else if (vec[vec.size() - 1] < temp)
			vec.push_back(temp);
		// 마지막 수 보다 temp가 더 작으면 , lower bound에 추가
		else if (vec[vec.size() - 1] >= temp)
		{
			//int lo = lowerBound(temp); 
			// 직접 lowerBound를 구하는것도 가능!
			int lo = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();	//temp의 lower bound를 구함
			// lower_bound의 반환형은 iterator 이여서 , vec의 첫번째 주소값을 빼 줘야함?
			vec[lo] = temp;
		}
	}

	cout << vec.size();

}
