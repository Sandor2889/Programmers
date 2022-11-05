#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool flag = true; // ���� ���� ù ���ĺ�

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == ' ') // ���� �϶�
        {
            answer += *it;
            flag = true;
        }
        else if (!isalpha(*it)) // ���ĺ��� �ƴҶ� (������ ���ܵ� ������ ���)
        {
            answer += *it;
            flag = false;
        }
        else // ���ĺ� �϶�
        {
            if (flag && islower(*it))  // ù ���ĺ��̰� �ҹ����̸� �빮�ڷ� ��ȯ�Ͽ� �ֱ�
            {
                answer += toupper(*it);
                flag = false;
            }
            else if (flag && isupper(*it)) // ù ���ĺ��̰� �빮��
            {
                answer += *it;
                flag = false;
            }
            else if (!flag && isupper(*it))   // ù ���ĺ��� �ƴϰ� �빮��
            {
                answer += tolower(*it);
            }
            else // ù ���ĺ��� �ƴϰ� �ҹ���
            {
                answer += *it;
            }
        }
    }

    return answer;
}

int main()
{
    string s = { "3people unFollowed me" };

    string answer = solution(s);
    cout << answer;

    return 0;
}

