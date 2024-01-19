
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
#include<unordered_map>

int N, M, R, C;
string str;

void input()
{
	cin >> str;
}

void solve()
{
	bool flag = false;	// -가 나왓는지 아닌지 
	string temp = "";
	int answer = 0;

	// -가 나오면 뒤에 있는 + 들은다 빼준다
	for (int i = 0; i <= str.length(); i++)
	{
		char next = str[i];

		// 부호일때
		if (next == '+' || next == '-' || i == str.size())	//끝일때도 포함 
		{
			// 앞에 -가 안 나왔을 때
			if (flag == false)
			{
				answer += stoi(temp);
				temp = "";
			}

			// 앞에 -가 나왓을 때
			else if (flag == true)
			{
				answer -= stoi(temp);
				temp = "";
			}
		}

		// 숫자일 때
		else
		{
			temp += next;
		}

		if (next == '-')
			flag = true;

	}

	cout << answer;
}

void print()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 프로그램을 종료
	// return : 함수 안에서 사용하면, 그 함수를 즉시 종료하고 함수를 호출한 곳으로 jump 함
	// typeid(x).name() : 자료형 출력

	input();
	solve();
	print();
}
