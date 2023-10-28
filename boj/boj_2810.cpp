
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

int n;
char c;
bool flag;
double sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'S') sum++;
		else //(c == 'L')
		{
			flag = true;
			sum += 0.5;
		}
	}

	if (flag) cout << sum + 1;
	else cout << sum;


}
