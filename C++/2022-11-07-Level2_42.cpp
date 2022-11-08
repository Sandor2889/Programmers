#include <iostream>
#include <string>
#include <vector>

#define MAX 1001

using namespace std;

int triangle[MAX][MAX];

vector<int> solution(int n)
{
    vector<int> answer;

    int total = n * (n + 1) / 2; // ������ �� ����

    // �迭�� ����, ����
    int row = -1;
    int column = 0;

    int cnt = n; // n, n-1, n-2 ...
    int trigger = 0; // �ﰢ���� ������ ���� �б�

    for (int i = 0; i < total; ++i)
    {
        if (i == cnt)
        {
            ++trigger;
            cnt += n - trigger;
        }

        switch (trigger % 3)
        {
        case 0: // �º� ( row ����)
            ++row;
            break;
        case 1: // �غ� ( column ����)
            ++column;
            break;
        case 2: // �캯 (row�� column ����)
            --row;
            --column;
            break;
        }

        triangle[row][column] = i + 1;
    }

    // �� ����
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