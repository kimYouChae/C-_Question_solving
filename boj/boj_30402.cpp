
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

int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	int n = 15;
	int arr[16][16];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;
			arr[i][j] = ch;
		}
	}

	bool is = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch = arr[i][j];
			if (ch == 'w')
			{
				cout << "chunbae";
				is = false;
				break;
			}
			else if (ch == 'b')
			{
				cout << "nabi";
				is = false;
				break;
			}
			else if (ch == 'g')
			{
				cout << "yeongcheol";
				is = false;
				break;
			}
		}
		if (!is)
			break;
	}
}

