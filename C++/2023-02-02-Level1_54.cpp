#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int rank[7] = { 6, 6, 5, 4, 3, 2, 1 };
    int correctNum = 0;
    int zeroCnt = 0;

    // ��ġ�ϴ� ��ȣ ī����
    for (int i : lottos)
    {
        if (i == 0) { ++zeroCnt; continue; }

        if (find(win_nums.begin(), win_nums.end(), i) != win_nums.end())
        {
            ++correctNum;
        }
    }

    // �ְ� ���� = ã�� ��ȣ�� �� + 0�� ��
    // ���� ���� = ã�� ��ȣ�� ��
    int maxRank = rank[correctNum + zeroCnt];
    int minRank = rank[correctNum];

    answer.push_back(maxRank);
    answer.push_back(minRank);

    return answer;
}

int main()
{
    vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
    
    vector<int> answer = solution(lottos, win_nums);
    cout << answer[0] << ", " << answer[1];

    return 0;
}