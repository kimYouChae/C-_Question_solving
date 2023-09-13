
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

int N, M, Q;
int alpha[27]; //¾Ë¹ÙÆê

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//¹éÁØ 1439
	string str;
	cin >> str;

	int zero = 0;
	int one = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i + 1] != str[i])
		{
			if (str[i] == '0') zero++;
			else one++;
		}
	}

	cout << min(zero, one);

}
