#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� Ǯ��
int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<int> res;
    int size = land.size();

    //  ������ ������ ���� ���� �ڱ� ���� ������ �� �� ���� ū ���� ã�� ���ϸ� ����
    for (int i = 1; i < size; ++i)
    {
        land[i][0] += max(land[i-1][1], max(land[i-1][2], land[i-1][3]));
        land[i][1] += max(land[i-1][0], max(land[i-1][2], land[i-1][3]));
        land[i][2] += max(land[i-1][0], max(land[i-1][1], land[i-1][3]));
        land[i][3] += max(land[i-1][0], max(land[i-1][1], land[i-1][2]));

        // ������ �࿡ ������ 4���� ���� ���� ���� vector�� ����
        if (i == size - 1)
        {
            res.push_back(land[i][0]);
            res.push_back(land[i][1]);
            res.push_back(land[i][2]);
            res.push_back(land[i][3]);
        }
    }

    return answer = *max_element(res.begin(), res.end());
}

// -------------------------------- �ð� �ʰ� �׽�Ʈ ���� ------------------------------------------------
vector<int> res;
int prohibitColumn = -1;    // ���� ��

void sumValue(vector<vector<int>>& land, int row, int prohibitColumn, int sum)
{
    if (row >= land.size()) { res.push_back(sum); return; }

    for (int column = 0; column < 4; ++column)
    {
        if (prohibitColumn != column)
        {
            sumValue(land, row + 1, column, sum + land[row][column]);
        }
    }
}

// ����Ž�� ��� Ȱ��
int solutionFail(vector<vector<int>> land)
{
    int answer = 0;
    sumValue(land, 0, prohibitColumn, answer);
    return answer = *max_element(res.begin(), res.end());
}

// --------------------------------------------------------------------------------------------------------
int main()
{
    vector<vector<int>> land =
    {
        {1, 2, 3, 5},
        {5, 6, 7, 8},
        {4, 3, 2, 1}
    };
    int answer = solution(land);
    cout << answer;

    return 0;
}