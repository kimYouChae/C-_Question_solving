
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


const int MAX = 1001;
int dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 lcs
	// longest common subseqeunce : 연속 x 최대 공통 수열
	// 코드는 똑같은데 왜 안돌아감 ?ㅅ?

	string a, b;
	cin >> a >> b;

	int a_size = a.length();
	int b_size = b.length();

	for (int i = 1; i <= a_size; i++)
	{
		for (int j = 1; j <= b_size; j++)
		{
			if (b[i - 1] == a[j - 1]) //b첫번째랑 a의 i번째랑 다르면
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			else //같으면
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				// 위랑 왼쪽에 있는것 중에 작은값
			}

		}
	}

	cout << dp[a_size][b_size];


}
