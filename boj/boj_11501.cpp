
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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준  
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		vector<int> vec;

		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;

			vec.push_back(temp);
		}

		//뒤에서 부터 max 보다 작으면
		// max - 해당 값 을 answer에 더하고
		// max 보다 크면 max 값을 바꾼다
		int _max = -1;
		long long answer = 0;
		for (int j = M - 1; j >= 0; j--)
		{
			// max랑 vec[j]중에 더 큰거 기준으로
			//_max = max(_max, vec[j]);
			//answer += _max - vec[j];

			if (_max < vec[j])
			{
				_max = vec[j];
				continue;
			}
			else if (_max > vec[j])
				answer += _max - vec[j];
		}

		cout << answer << '\n';
	}

}
