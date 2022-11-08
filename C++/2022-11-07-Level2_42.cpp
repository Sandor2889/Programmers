#include <iostream>
#include <string>
#include <vector>

#define MAX 1001

using namespace std;

int triangle[MAX][MAX];

vector<int> solution(int n)
{
    vector<int> answer;

    int total = n * (n + 1) / 2; // 수열의 합 공식

    // 배열의 가로, 세로
    int row = -1;
    int column = 0;

    int cnt = n; // n, n-1, n-2 ...
    int trigger = 0; // 삼각형의 각변에 대한 분기

    for (int i = 0; i < total; ++i)
    {
        if (i == cnt)
        {
            ++trigger;
            cnt += n - trigger;
        }

        switch (trigger % 3)
        {
        case 0: // 좌변 ( row 증가)
            ++row;
            break;
        case 1: // 밑변 ( column 증가)
            ++column;
            break;
        case 2: // 우변 (row와 column 감소)
            --row;
            --column;
            break;
        }

        triangle[row][column] = i + 1;
    }

    // 값 대입
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<int> answer = solution(4);

    for (int i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}