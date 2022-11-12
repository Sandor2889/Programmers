#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        // 짝수 일땐 +1이 제일 작은 수 (최하위 비트가 0에서 1로 바뀜)
        if (numbers[i] % 2 == 0) { answer.push_back(numbers[i] + 1); }
        else // 홀수일 경우 (참고 풀이)
        {
            // 최하위 비트에서부터 1이 끝나는 자리에 1 더해주기
            long long bit = 1;
            while ((numbers[i] & bit) != 0)
            {
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(numbers[i] + bit);
        }
    }

    return answer;
}

// --------------------------- 10, 11 시간 초과 ---------------------------------
vector<long long> solutionFail(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        long long current = numbers[i];
        long long next = numbers[i];
        // And 연산하기
        while (true)
        {
            int oneCnt = 0; // 1의 개수
            ++next;
            long long res = current ^ next;   // (XOR) 각 항이 다르면 1 

            // res가 가진 1의 수 새기
            long long temp = res;
            while (temp > 0)
            {
                oneCnt += temp % 2;
                temp /= 2;
            }

            if (oneCnt <= 2) { answer.push_back(next); break; }
        }
    }

    return answer;
}
//-----------------------------------------------------------------------------

int main()
{
    vector<long long> numbers = { 2, 7 };
    vector<long long> answer = solution(numbers);
    
    for (long long i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}
