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
        cnt++;  // 변환 수

        // '0'  카운팅
        for (char i : s)
        {
            if (i == '0') { zero++; }
        }

        // '0' 제거
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        // 십진수를 이진수로 변환
        int decimal = s.size();
        int binary = 0;
        stack<int> data;
        while (decimal / 2 > 0)
        {
            data.push(decimal % 2);
            decimal /= 2;
        }
        data.push(1);   // 마지막은 항상 1이 나오고 넣어준다.

        // stack의 숫자를 s에 대입
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

