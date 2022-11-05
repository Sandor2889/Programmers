#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// citations 내에 h 보다 큰 숫자가 몇개 있는지 반환
int getHowMany(vector<int>& citations, int h)
{
    int cnt = 0;
    for (int i = 0; i < citations.size(); ++i)
    {
        if (h <= citations[i])
        {
            ++cnt;
        }
    }

    return cnt;
}

int solution(vector<int> citations)
{
    int answer = 0;

    // 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());

    // 최댓값부터 1씩 감소하여 H-Index 찾기
    int max = citations[0];
    int loop = 0;
    while (max - loop > 0)
    {
        int hIdx = max - loop;
        if (hIdx <= getHowMany(citations, hIdx))
        {
            answer = hIdx;
            break;
        }

        ++loop;
    }

    return answer;
}

int main()
{
    vector<int> citations = { 3, 0, 6, 1, 5 };
    int answer = solution(citations);

    cout << answer;
}