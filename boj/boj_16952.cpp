
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
int M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 백준 169523 
	cin >> N >> M;

	int cnt = 0;
	string str = to_string(M);

	while (true)
	{
		//cout << M << " / " << str << endl;
		cnt++;

		if (M == N)
		{
			cout << cnt << endl;
			break;
		}

		if (M % 2 != 0 && str[str.length() - 1] != '1')
		{
			cout << -1 << '\n';
			break;
		}
		if (M < N || stoi(str) < N)
		{
			cout << -1 << '\n';
			break;
		}


		if (M % 2 == 0) //2로 나눠지면
		{
			M = M / 2;
			str = to_string(M);
			continue;
		}
		else if (str[str.length() - 1] == '1') //1로 끝나면
		{
			str = str.substr(0, str.length() - 1);
			M = stoi(str);
			continue;
		}

	}


}
