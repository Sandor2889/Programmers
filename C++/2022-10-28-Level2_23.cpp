#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// citations ���� h ���� ū ���ڰ� � �ִ��� ��ȯ
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

    // �������� ����
    sort(citations.begin(), citations.end(), greater<int>());

    // �ִ񰪺��� 1�� �����Ͽ� H-Index ã��
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