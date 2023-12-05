
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	// 모노스톤 스택 사용
	cin >> N;

	long long answer = 0;
	stack<int> sta;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!sta.empty())
		{
			if (sta.top() > num)	// sta.top이 볼 수 있으면
				break;
			sta.pop();			//볼 수 없으면 stack에서 하나 빼기
		}

		answer += (long long)sta.size();
		sta.push(num);

	}
}

