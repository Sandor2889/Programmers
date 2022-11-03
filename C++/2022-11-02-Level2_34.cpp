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
        int cnt = 0; // ������ ����
        string temp = "";
        string key = "";
        string trigg = "";

        for (auto it = record[i].begin(); ; ++it)
        {
            // ������ �ƴ� ������ ����
            if (it == record[i].end() && cnt == 1) { key = temp; break; }   // Leave�� id�� ������
            else if (it == record[i].end() && cnt == 2) { log[key] = temp; break; } // �� ��°�� ��: name ����

            if (*it != ' ') { temp += record[i][it - record[i].begin()]; }
            else
            {
                if (cnt == 0) { trigg = temp; ++cnt; }         // ù ��° ����: trigger ����
                else if (cnt == 1) { key = temp; ++cnt; }      // �� ��° ����: userId ����                 

                temp = "";
            }
        }
        trigger.push_back({ trigg, key });
    }

    // Trigger�� ���� ����ϱ�
    for (int i = 0; i < trigger.size(); ++i)
    {
        string temp;
        if (trigger[i].first == "Enter")
        {
            temp = log[trigger[i].second] + "���� ���Խ��ϴ�.";
            answer.push_back(temp);
        }
        else if (trigger[i].first == "Leave")
        {
            temp = log[trigger[i].second] + "���� �������ϴ�.";
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