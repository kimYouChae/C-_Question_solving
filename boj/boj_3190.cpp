
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
int arr[101][101];
queue<pair<int, char>> dir;
int answer = 0;


int dirIdx = 1; // 방향 0 위, 1 오른, 2 아래 , 3 왼  
int dx[4] = { 0 , 1 , 0 , -1 };
int dy[4] = { -1 , 0 , 1 , 0 };


void input()
{
    cin >> N;    // N X N
    cin >> M;    // 사과 위치
    for (int i = 0; i < M; i++)
    {
        int ay, ax;
        cin >> ay >> ax;

        arr[ay][ax] = -1;    // 사과는 -1
    }
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        dir.push({ t, d });    // 시간, 방향
    }
}

void solve()
{
    // arr 에 -1은 사과 , 1은 뱀
    deque<pair<int, int>> dq; // 뱀의 좌표를 담아놓는
    dq.push_back({ 1,1 });    // 처음에는 1,1에 있음
    arr[1][1] = 1;  // 첫번쨰 칸에 뱀

    // dq
    // (front, 꼬리 ) 0 0 0 0 0 (back, 머리)

    while (true)
    {
        answer++;   // 총 몇초가 지났는지

        int nextY = dq.back().first + dy[dirIdx];  // dirInx에는 '오,아래,왼,위' 인덱스
        int nextX = dq.back().second + dx[dirIdx];

        // 만약 다음 좌표가 범위를 넘어서면?
        if (nextY <= 0 || nextX <= 0 || nextY > N || nextX > N)
            return;

        // 다음 좌표가 몸통이면 ? -> 머리가 몸통을 만나면 안됨
        if (arr[nextY][nextX] == 1)
            return;

        // 1. 다음 좌표가 사과가 아니면?
        if (arr[nextY][nextX] != -1)
        {
            arr[dq.front().first][dq.front().second] = 0;   // .꼬리 부분 좌표를 0으로
            dq.pop_front();  // 꼬리 좌표 꺼냄
        }

        // 2. 다음 좌표가 사과이면?
        // 덱의 front에 next 좌표 추가
        // 뱀의 꼬리는 움직이지 않음

        // 아래 두줄은 1번 , 2번 다 만족하는 코드임
        arr[nextY][nextX] = 1; // 다음좌표에 뱀 머리가 존재 -> 1로 채움 (방문처리랑 같음)
        dq.push_back({ nextY, nextX });

        // answer 즉 게임초가 dir 방향을 바꿔야 하는 시간초랑 같을 때
        // -> 방향을 바꿔야함
        if (answer == dir.front().first)
        {
            char ch = dir.front().second;   // 저장된 다음방향
            if (ch == 'D')  // 우측회전
                dirIdx = (dirIdx + 1) % 4;
            else    // 좌측회전
                dirIdx = (dirIdx + 3) % 4;

            dir.pop();
        }

    }
}

void print()
{
    cout << answer;
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
