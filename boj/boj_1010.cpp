
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


int dp[30][30];
int comb(int m, int n) {
	if (dp[m][n] > 0) return dp[m][n];
	if (m == n || n == 0) return 1;
	else {
		dp[m][n] = comb(m - 1, n - 1) + comb(m - 1, n);
		return dp[m][n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	// 백준  
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << comb(m, n) << "\n";
	}
	return 0;
}
