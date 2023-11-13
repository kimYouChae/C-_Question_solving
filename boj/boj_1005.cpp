
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
int A;
const int MAX = 1001;
int buildTIme[MAX]; // 걸리는 시간
vector<int> vec[MAX]; // 트리
int enterance[MAX]; // 진입차수
int dp[MAX];

void topologySort()
{
	queue<int> qu;
	// 진입 차수를 돌면서 진입차수가 0인걸 qu에 넣음
	for (int i = 1; i <= M; i++)
	{
		if (enterance[i] == 0)
		{
			qu.push(i);
			dp[i] = buildTIme[i]; //dp에 값 미리 넣어두기
		}
	}

	// 노드 갯수 ,N 만큼 위상정렬함
	for (int i = 1; i <= M; i++)
	{
		// 순환 되는 경우는 없는 듯
		int x = qu.front();
		qu.pop();

		for (int i = 0; i < vec[x].size(); i++)
		{
			int next = vec[x][i]; //vector에 연결 되어있는 다음
			dp[next] = max(dp[next], dp[x] + buildTIme[next]); // 내 앞에 연결 되어 있는거 +  내 시간
			if (--enterance[next] == 0)
				qu.push(next);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력
	cin >> N;
	while (N--)
	{
		cin >> M >> R; // 노드갯수, 테스트케이스 갯수

		// 다 초기화
		memset(buildTIme, 0, sizeof(buildTIme));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i <= M; i++)
			fill(vec[i].begin(), vec[i].end(), 0);


		// 걸리는 시간 입력
		for (int i = 1; i <= M; i++)
		{
			cin >> buildTIme[i]; // 걸리는 시간 
		}
		// 트리 연결
		for (int i = 0; i < R; i++)
		{
			int s, e;
			cin >> s >> e;
			vec[s].push_back(e);
			++enterance[e]; // 진입차수 + 1
		}
		cin >> A; // 꼭 지어야 할 건물 번호

		// 위상정렬
		topologySort();

		cout << dp[A] << '\n';
	}

}

