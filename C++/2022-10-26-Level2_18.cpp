#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    // 문자 하나씩 조건에 따라 data에 push 또는 pop
    stack<char> data;
    for (int i = 0; i < s.size(); i++)
    {
        // 1. 가장 최근에 data에 저장된 문자와 현재 s[i]의 문자를 비교
        // 2. 서로 다르면 push, 같으면 pop
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
