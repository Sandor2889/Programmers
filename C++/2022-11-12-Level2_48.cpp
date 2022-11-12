#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        // ¦�� �϶� +1�� ���� ���� �� (������ ��Ʈ�� 0���� 1�� �ٲ�)
        if (numbers[i] % 2 == 0) { answer.push_back(numbers[i] + 1); }
        else // Ȧ���� ��� (���� Ǯ��)
        {
            // ������ ��Ʈ�������� 1�� ������ �ڸ��� 1 �����ֱ�
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

// --------------------------- 10, 11 �ð� �ʰ� ---------------------------------
vector<long long> solutionFail(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        long long current = numbers[i];
        long long next = numbers[i];
        // And �����ϱ�
        while (true)
        {
            int oneCnt = 0; // 1�� ����
            ++next;
            long long res = current ^ next;   // (XOR) �� ���� �ٸ��� 1 

            // res�� ���� 1�� �� ����
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
