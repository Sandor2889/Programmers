#include <iostream>
#include<string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;

    // '(' 면 open을 증가하고 ')' 면 open을 감소시킨다.
    // open이 0이 되어야 올바르게 짝지어진 것이다.
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')    // ')' 이고 '(' 없을 경우 false 반환하고 종료
        {
            if (open == 0) { return false; }
            else { open -= 1; }
        }
        else  // '(' 이면 수량 증가 
        {
            open++;
        }
    }

    // open 괄호에 대한 짝(close)이 맞춰지지 않으면 false
    if (open != 0) { answer = false; }

    return answer;
}

int main()
{
    string s = { "(())()" };

    bool answer = solution(s);
    cout << answer;

    return 0;
}

