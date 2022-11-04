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
    map<string, pair<int, bool>> log; // 차번호, IN시간, IN상태
    map<string, int> res;               // 차번호, 최종시간

    for (int i = 0; i < records.size(); ++i)
    {
        string time, car, inOut;
        stringstream ss(records[i]);

        // 시간을 분으로 변환
        ss >> time;
        string hour = time.substr(0,2);
        string min = time.substr(3, 2);
        int sum = stoi(hour) * 60 + stoi(min);

        ss >> car;
        ss >> inOut;


        // IN, OUT 처리: IN이면 해당 차번호 인덱스는 True, OUT이면 `나간 시간 - 들어온 시간`
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

    // 들어왔지만 나가지 않은 차에 대한 처리
    for (auto it = log.begin(); it != log.end(); ++it)
    {
        if (it->second.second)  // OUT을 하지 않았으면 True 상태
        {
            res[it->first] += MAX_TIME - it->second.first;
        }
    }

    // 요금 계산
    for (auto it = res.begin(); it != res.end(); ++it)
    {
        int payment = 0;    // 주차 요금
        if (res[it->first] > fees[0])   // 시간 초과로 추가 요금 할당
        {
            if ((res[it->first] - fees[0]) % fees[2] == 0)  // 나누어 떨어지는 경우
            {
                payment = fees[1] + (res[it->first] - fees[0]) / fees[2] * fees[3];
            }
            else
            {
                payment = fees[1] + ((res[it->first] - fees[0]) / fees[2] + 1) * fees[3];
            }        
        }
        else // 기본 요금 계산
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