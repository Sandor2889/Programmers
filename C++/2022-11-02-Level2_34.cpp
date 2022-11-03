#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    unordered_map<string, string> log;     // (id, name)
    vector<pair<string, string>> trigger;  // (Enter Leave Change, id)


    for (int i = 0; i < record.size(); ++i)
    {
        int cnt = 0; // 공백의 순서
        string temp = "";
        string key = "";
        string trigg = "";

        for (auto it = record[i].begin(); ; ++it)
        {
            // 공백이 아닌 마지막 지점
            if (it == record[i].end() && cnt == 1) { key = temp; break; }   // Leave는 id가 마지막
            else if (it == record[i].end() && cnt == 2) { log[key] = temp; break; } // 세 번째의 끝: name 저장

            if (*it != ' ') { temp += record[i][it - record[i].begin()]; }
            else
            {
                if (cnt == 0) { trigg = temp; ++cnt; }         // 첫 번째 공백: trigger 저장
                else if (cnt == 1) { key = temp; ++cnt; }      // 두 번째 공백: userId 저장                 

                temp = "";
            }
        }
        trigger.push_back({ trigg, key });
    }

    // Trigger에 따라 출력하기
    for (int i = 0; i < trigger.size(); ++i)
    {
        string temp;
        if (trigger[i].first == "Enter")
        {
            temp = log[trigger[i].second] + "님이 들어왔습니다.";
            answer.push_back(temp);
        }
        else if (trigger[i].first == "Leave")
        {
            temp = log[trigger[i].second] + "님이 나갔습니다.";
            answer.push_back(temp);
        }
        else { continue; }
    }

    return answer;
}

int main()
{
    vector<string> record = 
    { 
        "Enter uid1234 Muzi", 
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };


    vector<string> answer = solution(record);

    return 0;
}