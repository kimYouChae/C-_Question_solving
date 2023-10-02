
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
vector<int> vec;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : 함수에서 출력하고 바로끝내기
	// typeid(x).name() : 자료형 출력

	//백준 14425
	string str;
	cin >> str;

	long long sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		vec.push_back(str[i] - '0');
		sum += str[i] - '0'; // 각 자릿수 더하기
	}

	sort(vec.begin(), vec.end(), greater<>());

	if (sum % 3 == 0 && vec[vec.size() - 1] == 0) //각 자리 수의 합이 3의 배수이고 마지막 수가 0이여야 -> 3의 배수
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
		}
	}
	else
		cout << -1;


}
