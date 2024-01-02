
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
vector<int> crain;
vector<int> box;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		crain.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		box.push_back(temp);
	}

}

void solve()
{
	// 둘다 정렬
	sort(crain.rbegin(), crain.rend());	// 내림차순 정렬
	sort(box.rbegin(), box.rend());

	int answer = 0;

	// 불가능한 경우
	// 크레인이 들 수 있는 무게보다 box가 더 크면
	if (crain.front() < box.front())
	{
		cout << -1;
		return;
	}

	// weight에서 해당 상자를 옮길수 있으면 vector에서 remove
	while (!box.empty())
	{
		// box가 남아있으면
		answer++;
		for (int i = 0; i < N; i++)
		{
			int we = crain[i];

			for (int j = 0; j < box.size(); j++)
			{
				if (we >= box[j])
				{
					// 옮길수 있으면 삭제
					box.erase(box.begin() + j);	//box의 j 번째 요소 지우기
					break;
				}
			}
		}
	}
	cout << answer;

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
