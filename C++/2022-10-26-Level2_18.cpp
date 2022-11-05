#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // ���� �ϳ��� ���ǿ� ���� data�� push �Ǵ� pop
    stack<char> data;
    for (int i = 0; i < s.size(); i++)
    {
        // 1. ���� �ֱٿ� data�� ����� ���ڿ� ���� s[i]�� ���ڸ� ��
        // 2. ���� �ٸ��� push, ������ pop
        if (data.empty() || data.top() != s[i]) { data.push(s[i]); }   
        else { data.pop(); }
    }

    if (data.empty()) { answer = 1; }

    return answer;
}

int main()
{
    string s = { "baabaa" };

    int answer = solution(s);
    cout << answer;

    return 0;
}
