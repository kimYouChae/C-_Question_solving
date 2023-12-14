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

const int MAX = 1010;
const int INF = 2000000000;
int Nstart = 0;
int Nend = 0;
vector<pair<int, int>> vec[MAX];
int d[MAX];
int route[MAX];

void dijstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, Nstart));
	d[Nstart] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist > d[node])	//이게 없어서 시간 초과 난듯!
			continue;

		for (int i = 0; i < vec[node].size(); i++)
		{
			int next = vec[node][i].first;
			int nextdist = vec[node][i].second;

			if (d[next] > nextdist + dist)
			{
				route[next] = node;	// next 노드를 오기 위해서는 node(현재노드)를 거쳐야함
				d[next] = nextdist + dist;
				pq.push({ -d[next], next });
			}
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

	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		d[i] = INF;

	for (int i = 0; i < M; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		vec[s].push_back({ e, d });
	}

	cin >> Nstart >> Nend;
	dijstra();


	// 경로 설정 다 하고 난 후
		// 출력1 : 도착지의 최소 경로
	cout << d[Nend] << '\n';

	vector<int> route_vec;
	int temp = Nend;
	while (temp) // temp가 존재할 때
	{
		route_vec.push_back(temp);
		temp = route[temp];
	}
	// temp = 5 , 5에 오려면 3을 거쳐야함 3 = temp
	// temp = 3 . 3에 오려면 1을 거쳐야함 1 = temp
	// temp = 1 , 1에 오려면 0을 거져야함 -> while문 종료

	// 출력2 : 도착지까지 최단경로로 오는 노드 갯수
	cout << route_vec.size() << '\n';

	// 출력3 : 지나온 노드 출력
	for (int i = route_vec.size() - 1; i >= 0; i--)
	{
		cout << route_vec[i] << " ";
	}
	cout << '\n';
}

