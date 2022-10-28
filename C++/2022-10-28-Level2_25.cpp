#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // 회전 수
    for (int i = 0; i < s.size(); ++i)
    {
        stack<char> parentheses;

        // s에대한 문자 루프
        for (int j = 0; j < s.size(); ++j)
        {
            // 열린 괄호는 stack에 push
            if (s[j] == '(' || s[j] == '{' || s[j] == '[') { parentheses.push(s[j]); }
            else  // 닫힌 괄호가 들어온다면
            {
                // 빈 공간에 닫히 괄호가 들어오면 종료
                if (parentheses.empty()) { parentheses.push(s[j]); break; }
                else
                {
                    // 맞는 짝이 오면 pop
                    if (parentheses.top() == '(' && s[j] == ')') { parentheses.pop(); }
                    else if (parentheses.top() == '{' && s[j] == '}') { parentheses.pop(); }
                    else if (parentheses.top() == '[' && s[j] == ']') { parentheses.pop(); }
                    // 짝이 맞지 않으면 종료
                    else { break; }
                }
            }
        }

        if (parentheses.empty()) { ++answer; }

        // 회전 - 가장 앞의 문자를 맨 뒤로 보내기
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