
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

int N, M, S;
string arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 
	string s;
	getline(cin, s);
	string answer = "UCPC";

	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U' && temp.empty())
			temp += 'U';
		else if (s[i] == 'C' && temp == "U")
			temp += 'C';
		else if (s[i] == 'P' && temp == "UC")
			temp += 'P';
		else if (s[i] == 'C' && temp == "UCP")
			temp += 'C';
	}

	if (temp == answer)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

}
