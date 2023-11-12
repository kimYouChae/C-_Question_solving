
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	string str;
	while (cin >> str)
	{
		// 종료 조건
		if (str == "end")
			break;

		bool answer = true;
		bool flag = false;
		int con = 0; // 연속 자음의 갯수
		int vow = 0; // 연속 모음의 갯수
		for (int i = 0; i < str.length(); i++)
		{

			char ch = str[i];

			// 모음이면? 
			bool is = false;
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			{
				is = true;

			}

			if (is)
			{
				// 모음이면
				flag = true;
				con = 0;
				vow++;
			}
			else //자음이면 
			{
				con++;
				vow = 0;
			}

			// 3개씩 연속되면? (조건2)
			if (con == 3 || vow == 3)
			{
				answer = false;
				break;
			}
			// 같은 두개 문자가 오면? (조건3)
			if (i > 0 && str[i - 1] == str[i] && !(ch == 'e' || ch == 'o'))
			{
				answer = false;
				break;
			}
		}

		if (!flag)
			answer = false;

		if (answer)
			cout << "<" << str << "> is acceptable.\n";
		else
			cout << "<" << str << "> is not acceptable.\n";
	}


}

