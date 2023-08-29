
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M;
int answer = 0;
int parent[10001];
vector<pair <int, pair<int, int>>> vec; // dis , <노드 1 , 노드 2>;


// union-find 알고리즘을 그대로 사용함!
// 부모 가져오기 
int getParent(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	int myParent = parent[a];
	return parent[a] = getParent(myParent);
}

// 부모 합치기
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a > b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

//부모가 같은지?
bool isSameParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 1197 : 최소신장트리 구현
	// 1. vector<pair<int, pair<int,int>>>를 사용해서 구현
	// 2. turple 사용해서 구현
	cin >> N;
	cin >> M;

	//입력
	for (int i = 0; i < M; i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;

		pair <int, int> pa = make_pair(from, to);

		vec.push_back(make_pair(dis, pa));
	}

	sort(vec.begin(), vec.end()); // {a , {b, c}}일때 a를 기준으로, a가 같으면 b,c순
	// 여기서는 dis순으로 !

	//처음에 각 노드의 부모는 본인
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		//vec의 i번째 pair의 first(노드)와 second(노드)를 비교
		// 부모가 다르다 -> 사이클을 생성하지 않는다 (문제조건)
		if (isSameParent(vec[i].second.first, vec[i].second.second) == false)
		{
			unionParent(vec[i].second.first, vec[i].second.second);
			answer += vec[i].first; //dis값
		}
	}

	cout << answer;
}




 
