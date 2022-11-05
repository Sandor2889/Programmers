#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool flag = true; // 공백 이후 첫 알파벳

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == ' ') // 공백 일때
        {
            answer += *it;
            flag = true;
        }
        else if (!isalpha(*it)) // 알파벳이 아닐때 (공백이 제외된 숫자인 경우)
        {
            answer += *it;
            flag = false;
        }
        else // 알파벳 일때
        {
            if (flag && islower(*it))  // 첫 알파벳이고 소문자이면 대문자로 변환하여 넣기
            {
                answer += toupper(*it);
                flag = false;
            }
            else if (flag && isupper(*it)) // 첫 알파벳이고 대문자
            {
                answer += *it;
                flag = false;
            }
            else if (!flag && isupper(*it))   // 첫 알파벳이 아니고 대문자
            {
                answer += tolower(*it);
            }
            else // 첫 알파벳이 아니고 소문자
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

