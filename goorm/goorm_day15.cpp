
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
long long M;
vector<tuple<long long, long long, long long>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 구름챌린지
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		long long p, c;
		cin >> p >> c;

		vec.push_back(make_tuple(c / p, c, p)); //조각난 포만감 ,  포만감 , 가격
	}

	sort(vec.begin(), vec.end(), greater<>()); // 조각난 포만감 순으로 내림차순

	/*
	for (int i = 0; i < vec.size(); i++)
	{
		cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << " " << get<2>(vec[i]) << endl;
	}
	*/

	long long myC = 0; //포만감
	long long myP = 0; //가격

	for (int i = 0; i < N; i++)
	{
		long long divC = get<0>(vec[i]); //한조각 포만감
		long long c = get<1>(vec[i]); // 포만감
		long long p = get<2>(vec[i]); // 가격

		if (myP + p <= M) //가격이 작으면
		{
			myC += c;
			myP += p;
			continue;
		}
		else
		{
			while (myP < M)
			{
				myP += 1;
				myC += divC;
			}
			break;
		}

	}

	cout << myC;

}
