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
const int MAX = 3000001;

int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	cin >> N >> M >> R >> C; // 접시수, 초밥 가짓수, 연속 접시수, 쿠폰 
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = R - 1;
	unordered_map<int, int> ma;
	int answer = 0;

	for (int i = 0; i < R - 1; i++)
		ma[arr[i]]++;	// 처음 연속 접시수 -1 까지 넣어놓기

	// 회전초밥이여서 한바퀴
	for (int i = 0; i < N; i++)
	{
		end %= N;

		cout << start << " / " << end << endl;

		//start랑 end는 계속 증가
		ma[arr[end]]++;		// 구간이 하나 늘어나면 end 부분 숫자가 하나더 
		ma[arr[start]]--;	// 구간이 하나 줄어들면 start부분 숫자 없어짐

		int s = ma.size();
		// map안에 쿠폰이 없다면 ?
		// 없으면 + 1 ( map에 들어있는 초밥의 종류 + 쿠폰으로 초밥종류(1) )
		if (ma.find(C) == ma.end())
			answer = max(answer, s + 1);
		else
			answer = max(answer, s);

		// 구간이 하나 줄어들 때, 해당 숫자가 map에 없으면
		// map에서 지우기
		if (ma[arr[start]] == 0)
			ma.erase(ma.find(arr[start]));

		start++;
		end++;

	}

	cout << answer;

}
