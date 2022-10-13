#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        int time = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            time++;

            // 현재 가격 'i'와 다음 가격들'j' 비교
            if (prices[i] > prices[j])
            {
                break;
            }
        }
        answer.push_back(time);
    }

    return answer;
}

int main()
{
    vector<int> prices = {1, 2, 3, 2, 3 };
    vector<int> answer = solution(prices);

    for (auto i: answer)
    {
        cout << i << ' ';
    }

    return 0;
}