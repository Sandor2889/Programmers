#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 참고 풀이
int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<int> res;
    int size = land.size();

    //  각각의 열에서 다음 행의 자기 열을 제외한 값 중 가장 큰 값을 찾아 더하며 갱신
    for (int i = 1; i < size; ++i)
    {
        land[i][0] += max(land[i-1][1], max(land[i-1][2], land[i-1][3]));
        land[i][1] += max(land[i-1][0], max(land[i-1][2], land[i-1][3]));
        land[i][2] += max(land[i-1][0], max(land[i-1][1], land[i-1][3]));
        land[i][3] += max(land[i-1][0], max(land[i-1][1], land[i-1][2]));

        // 마지막 행에 도달한 4개의 열에 대한 값을 vector에 저장
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

// -------------------------------- 시간 초과 테스트 실패 ------------------------------------------------
vector<int> res;
int prohibitColumn = -1;    // 금지 열

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

// 완전탐색 재귀 활용
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