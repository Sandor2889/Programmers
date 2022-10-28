#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // ȸ�� ��
    for (int i = 0; i < s.size(); ++i)
    {
        stack<char> parentheses;

        // s������ ���� ����
        for (int j = 0; j < s.size(); ++j)
        {
            // ���� ��ȣ�� stack�� push
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') { parentheses.push(s[j]); }
            else  // ���� ��ȣ�� ���´ٸ�
            {
                // �� ������ ���� ��ȣ�� ������ ����
                if (parentheses.empty()) { parentheses.push(s[j]); break; }
                else
                {
                    // �´� ¦�� ���� pop
                    if (parentheses.top() == '(' && s[j] == ')') { parentheses.pop(); }
                    else if (parentheses.top() == '{' && s[j] == '}') { parentheses.pop(); }
                    else if (parentheses.top() == '[' && s[j] == ']') { parentheses.pop(); }
                    // ¦�� ���� ������ ����
                    else { break; }
                }
            }
        }

        if (parentheses.empty()) { ++answer; }

        // ȸ�� - ���� ���� ���ڸ� �� �ڷ� ������
        char frist = s.front();
        s.erase(s.begin());
        s += frist;
    }
    return answer;
}

int main() 
{
    string s = { "[](){}" };
    int answer = solution(s);
    cout << answer;

    return 0;
}