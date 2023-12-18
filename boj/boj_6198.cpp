
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
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	// ��뽺�� ���� ���
	cin >> N;

	long long answer = 0;
	stack<int> sta;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!sta.empty())
		{
			if (sta.top() > num)	// sta.top�� �� �� ������
				break;
			sta.pop();			//�� �� ������ stack���� �ϳ� ����
		}

		answer += (long long)sta.size();
		sta.push(num);

	}
}
