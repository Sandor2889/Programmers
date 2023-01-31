#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ð��ʰ�
int solution_TimeOver(string s)
{
    int answer = 0;
    
    // ���ڿ��� ������ �ǰų� 1���Ϸ� ���������� �ݺ�
    while (!s.empty() && s.size() > 1)
    {
        char first = s[0];
        int firstCnt = 1;
        int secondCnt = 0;

        for (int i = 1; i < s.size(); ++i)
        {
            // ù ���ڿ� ������ firstCnt ���� �ٸ��� secondCnt ����
            if (first == s[i]) { ++firstCnt; }
            else { ++secondCnt; }

            // �� ������ ���� ������ ���ڿ� �߶󳻱�
            if (firstCnt == secondCnt)
            {
                s = s.substr(i + 1, s.size() - 1);
                ++answer;
                break;
            }
        }
    }

    // ������ ���ڿ��� ���� �� �� �������� ���
    if (!s.empty()) { ++answer; }

    return answer;
}

// ----------------------------------------------------------
// ����
int solution(string s)
{
    int answer = 0;

    int firstIdx = 0; // ���� ����
    char first = s[firstIdx];
    int firstCnt = 1;
    int secondCnt = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        // ù ���ڿ� ������ firstCnt ���� �ٸ��� secondCnt ����
        if (first == s[i]) { ++firstCnt; }
        else { ++secondCnt; }

        // �� ������ ���� ������
        if (firstCnt == secondCnt)
        {
            // idx ���� 
            ++i;
            firstIdx = i;

            //���� �ʱ�ȭ
            first = s[firstIdx];
            firstCnt = 1;
            secondCnt = 0;

            // ���ڿ� �� ����
            ++answer;
        }
    }

    // ���� ó��
    if (firstIdx != s.size()) { ++answer; }

    return answer;
}

int main()
{
    string s = "abracadabra";
    int answer = solution(s);
    cout << answer;

    return 0;
}