#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    // 왼손과 오른손 초기위치 <x,y>
    pair<int, int> lPos;
    lPos.first = 0;
    lPos.second = 3;
    pair<int, int> rPos;
    rPos.first = 2;
    rPos.second = 3;

    for (int i = 0; i < numbers.size(); i++)
    {
        // 0 에 대한 처리
        if (numbers[i] == 0) { numbers[i] = 11; }

        if (numbers[i] % 3 == 1) // 1, 4, 7
        {
            answer += "L";
            lPos.first = 0;
            lPos.second = numbers[i] / 3;
        }
        else if (numbers[i] % 3 == 0) // 3, 6, 9
        {
            answer += "R";
            rPos.first = 2;
            rPos.second = numbers[i] / 3 - 1;
        }
        else  // 2, 5, 8, 0
        {
            // 타겟으로부터 왼손과 오른손 거리 비교
            int targetX = 1;
            int targetY = numbers[i] / 3;
            int lDist = (targetX - lPos.first) + abs(targetY - lPos.second);
            int rDist = (rPos.first - targetX) + abs(rPos.second - targetY);

            if (lDist > rDist)
            {
                answer += "R";
                rPos.first = targetX;
                rPos.second = targetY;
            }
            else if (lDist < rDist)
            {
                answer += "L";
                lPos.first = targetX;
                lPos.second = targetY;
            }
            else // 위치 값이 같을 경우
            {
                if (hand == "left")
                {
                    answer += "L";
                    lPos.first = targetX;
                    lPos.second = targetY;
                }
                else
                {
                    answer += "R";
                    rPos.first = targetX;
                    rPos.second = targetY;
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers;
    string hand = "left";
    
    for (int i = 0; i < 11; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    string z = solution(numbers, hand);
    cout << z;

    return 0;
}