#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, K;
char arr[201][201];
int result[201][201];
int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (K--)
    {
        int y, x;
        cin >> y >> x;

        y--; x--;

        if (arr[y][x] == '0')
            result[y][x]++;
        else if (arr[y][x] == '@')
            result[y][x] += 2;
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;


            if (arr[ny][nx] == '0')
                result[ny][nx]++;
            else if (arr[ny][nx] == '@')
                result[ny][nx] += 2;
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (result[i][j] > max)
                max = result[i][j];
        }
    }
    cout << max;
}