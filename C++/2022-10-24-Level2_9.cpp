#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> data;

    string temp = "";
    for (auto it = s.begin(); ; it++)
    {
        // it�� end�� �����ϸ� temp�� data�� �ְ� ������
        if (it == s.end())
        {
            data.push_back(stoi(temp));
            temp = "";
            break;
        }

        // �����̸� data�� �ְ� temp �ʱ�ȭ
        if (*it == ' ')
        {
            data.push_back(stoi(temp));
            temp = "";
        }
        else    // ������ �ƴϸ� temp�� �ֱ�
        {
            temp += *it;
        }
    }

    // �ִ�, �ּ� ã��
    string min = to_string(*min_element(data.begin(), data.end()));
    string max = to_string(*max_element(data.begin(), data.end()));

    answer += min;
    answer += ' ';
    answer += max;

    return answer;
}

int main()
{
    string s = { "-1 -2 -3 -4" };

    string answer = solution(s);
    cout << answer;

    return 0;
}

