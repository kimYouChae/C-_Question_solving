
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
const int MAX = 10001;
vector<int> vec[MAX];
bool visit[MAX];

int ans;

void input()
{
	cin >> N;
}

void solve()
{

	// 연결 컨테이너 list 사용
	list<char> passwd;	// list
	list<char>::iterator it; // list의 iterator
	// vector의 iterator을 사용할 때도
	// vector<int>::iterator
	// 벡터 or 리스드<int>::iterator ->  특정 컨테이너와 연관된 iterator 객체 생성

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;


		passwd.clear();	// 초기화
		it = passwd.begin();	// list안의 특정 주솟값 즉 커서의 위치


		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];
			if (ch == '<')
			{
				// 커서가 맨 앞이라면?
				if (it == passwd.begin())
					continue;

				// iterator가 맨 앞이 아닐 떄 
				// 커서 --
				it--;
			}
			else if (ch == '>')
			{
				// 커서가 맨 뒤가면?
				if (it == passwd.end())
					continue;

				// iterator가 맨 뒤가 아닐때
				// 커서 ++
				it++;
			}
			else if (ch == '-')
			{
				// 현재 커서 앞에 있는 문자열 지우가
				if (it == passwd.begin())
					continue;

				it = passwd.erase(--it);
				// list.erase(iterator) -> 삭제한 다음 원소의 iterator 반환
			}
			else
			{
				// 그냥 문자열일 때 삽입
				it = passwd.insert(it, ch);
				// iter 위치에 ch를 삽입 / 삽입한 iterator 반환
				it++;
			}

		}
		for (char ch : passwd)
			cout << ch;

		cout << endl;
	}
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
