#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> dic; //(알파벳, 번호)

    int idx;
    for (idx = 0; idx < 26; ++idx)
    {
        string alpha = "";
        alpha += (65 + idx);
        dic.insert({ alpha, idx + 1 });
    }

    for (int i = 0; i < msg.size(); ++i)
    {
        string temp = "";

        for (int j = i; j < msg.size(); ++j)
        {
            temp += msg[j];

            // 사전에 있는 문자면 + c 하기
            if (dic.find(temp) != dic.end())
            {
                // 마지막 도달시 처리
                if (j == msg.size()-1) 
                {
                    answer.push_back(dic[temp]);
                    return answer;
                }
            }
            // 사전에 없으면 w에 대한 색인 번호 출력, w+c 등록
            else
            {
                dic.insert({ temp, ++idx });   // 사전에 등록
                i = j-1;

                // 가장 뒤에있는 문자 빼고 색인번호 출력
                temp.pop_back();               
                answer.push_back(dic[temp]);
                
                break;
            }
        }
    }

    return answer;
}

int main()
{
    string msg = { "TOBEORNOTTOBEORTOBEORNOT" };
    vector<int> answer = solution(msg);

    for (int i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}