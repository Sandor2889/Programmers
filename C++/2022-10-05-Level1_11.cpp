#include <iostream>
#include <vector>

using namespace std;


bool primeNumSeive(int sum)
{
    for (int i = 2; i * i <= sum; i++)
    {
        if (sum % i == 0) { return false; }
    }

    return true;
}

int solution(vector<int> nums)
{
    int answer = 0;

    // 세 개의 수의 합
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (primeNumSeive(sum))
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main()
{
    // 입력
    vector<int> temp;
    int size = 5; // 입력 수
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        temp.push_back(num);
    }

    cout << solution(temp);

    return 0;
}