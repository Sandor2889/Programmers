#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> copyNums;
int cnt = 0;

void dfs(int node, int sum, int target)
{
    // 마지막 도달 시 총합 확인
    if (node == copyNums.size() - 1)
    {
        if (sum == target) { ++cnt; }
        return;
    }

    // +- 부호에 대한 각각 탐색
    for (int i = 0; i < 2; ++i)
    {
        if (i == 0) { dfs(node + 1, sum + copyNums[node + 1], target); }
        else { dfs(node + 1, sum - copyNums[node + 1], target); }
    }
}

// 완전탐색 + dfs
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    copyNums = numbers;
    dfs(-1, 0, target);

    return answer = cnt;
}

int main()
{
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int answer = solution(nums, 3);

    cout << answer;

    return 0;
}