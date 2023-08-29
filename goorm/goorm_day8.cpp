
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

int N;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지 8일차
	cin >> N;

	int result = 0;

	result += N / 14;
	N = N % 14;
	result += N / 7;
	N = N % 7;
	result += N / 1;
	N = N % 1;

	cout << result;

}
