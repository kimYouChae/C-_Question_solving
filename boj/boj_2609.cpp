
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


int N, M, R;

int get1(int x, int y)
{
	int r;
	while (y > 0)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int get2(int x, int y)
{
	return (x * y) / get1(x, y);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//백준 2609
	cin >> N >> M;

	//최대공약수 구하기
	int ge = get1(N, M);
	int ge2 = get2(N, M);
	cout << ge << '\n';
	cout << ge2 << '\n';
}
