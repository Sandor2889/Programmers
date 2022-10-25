#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int cnt = 0;
    int zero = 0;

    while (s.size() > 1)
    {
        cnt++;  // ��ȯ ��

        // '0'  ī����
        for (char i : s)
        {
            if (i == '0') { zero++; }
        }

        // '0' ����
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        // �������� �������� ��ȯ
        int decimal = s.size();
        int binary = 0;
        stack<int> data;
        while (decimal / 2 > 0)
        {
            data.push(decimal % 2);
            decimal /= 2;
        }
        data.push(1);   // �������� �׻� 1�� ������ �־��ش�.

        // stack�� ���ڸ� s�� ����
        s = "";
        while (!data.empty())
        {
            s += to_string(data.top());
            data.pop();
        }
    }

    answer.push_back(cnt);
    answer.push_back(zero);

    return answer;
}

int main()
{
    string s = { "110010101001" };

    vector<int> answer = solution(s);
    cout << answer[0] << ' ' << answer[1];

    return 0;
}

