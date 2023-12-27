
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
vector<int> vec;

int nearNum()
{
	int start = 0;
	int end = vec.size() - 1;

	long long min = 9000000000000000000;	// 최소값 구하니까 최대로
	long long answer = 0;	// 최소값이랑 값이 같은거
	while (true)
	{
		if (start >= end)	// 종료조건
			break;

		// 초기 min은 (-7 + 12)
		if (abs(R - (vec[start] + vec[end])) < min)
		{
			min = abs(R - vec[start] - vec[end]);
			answer = 0;	// 최솟값 정할 때 초기화
		}

		// min이랑 같으면? (초기 min 구한 -7 + 12도 포함)
		if (abs(R - (vec[start] + vec[end])) == min)
			answer++;

		// start + end 더한게 R보다 크면 end--
		if (vec[start] + vec[end] > R)
			end--;
		// start + end 더한게 R보다 작으면 start++
		else
			start++;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vec.clear();	// 벡터 초기화
		cin >> M >> R;

		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			vec.push_back(temp);
		}

		// 정렬
		sort(vec.begin(), vec.end());

		// 가까운수 구하기
		int ans = nearNum();
		cout << ans << '\n';
	}


}
