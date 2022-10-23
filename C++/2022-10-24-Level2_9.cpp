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
        // it이 end에 도달하면 temp를 data에 넣고 끝내기
        if (it == s.end())
        {
            data.push_back(stoi(temp));
            temp = "";
            break;
        }

        // 공백이면 data에 넣고 temp 초기화
        if (*it == ' ')
        {
            data.push_back(stoi(temp));
            temp = "";
        }
        else    // 공백이 아니면 temp에 넣기
        {
            temp += *it;
        }
    }

    // 최대, 최소 찾기
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

