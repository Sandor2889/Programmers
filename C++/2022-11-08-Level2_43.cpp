#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> dic; //(���ĺ�, ��ȣ)

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

            // ������ �ִ� ���ڸ� + c �ϱ�
            if (dic.find(temp) != dic.end())
            {
                // ������ ���޽� ó��
                if (j == msg.size()-1) 
                {
                    answer.push_back(dic[temp]);
                    return answer;
                }
            }
            // ������ ������ w�� ���� ���� ��ȣ ���, w+c ���
            else
            {
                dic.insert({ temp, ++idx });   // ������ ���
                i = j-1;

                // ���� �ڿ��ִ� ���� ���� ���ι�ȣ ���
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