#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#define MAX_TIME 1439

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, pair<int, bool>> log; // ����ȣ, IN�ð�, IN����
    map<string, int> res;               // ����ȣ, �����ð�

    for (int i = 0; i < records.size(); ++i)
    {
        string time, car, inOut;
        stringstream ss(records[i]);

        // �ð��� ������ ��ȯ
        ss >> time;
        string hour = time.substr(0,2);
        string min = time.substr(3, 2);
        int sum = stoi(hour) * 60 + stoi(min);

        ss >> car;
        ss >> inOut;


        // IN, OUT ó��: IN�̸� �ش� ����ȣ �ε����� True, OUT�̸� `���� �ð� - ���� �ð�`
        pair<int, bool> temp;
        if (inOut == "IN")
        {
            temp.first = sum;
            temp.second = true;
            log[car] = temp;
        }
        else
        {
            temp.first = 0;
            temp.second = false;
            res[car] += sum - log[car].first;
            log[car] = temp;
        }
    }

    // �������� ������ ���� ���� ���� ó��
    for (auto it = log.begin(); it != log.end(); ++it)
    {
        if (it->second.second)  // OUT�� ���� �ʾ����� True ����
        {
            res[it->first] += MAX_TIME - it->second.first;
        }
    }

    // ��� ���
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        int payment = 0;    // ���� ���
        if (res[it->first] > fees[0])   // �ð� �ʰ��� �߰� ��� �Ҵ�
        {
            if ((res[it->first] - fees[0]) % fees[2] == 0)  // ������ �������� ���
            {
                payment = fees[1] + (res[it->first] - fees[0]) / fees[2] * fees[3];
            }
            else
            {
                payment = fees[1] + ((res[it->first] - fees[0]) / fees[2] + 1) * fees[3];
            }        
        }
        else // �⺻ ��� ���
        {
            payment = fees[1];
        }
        answer.push_back(payment);
    }

    return answer;
}

int main()
{
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = 
    { 
        "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
        "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
        "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" 
    };
    vector<int> answer = solution(fees, records);

    return 0;
}