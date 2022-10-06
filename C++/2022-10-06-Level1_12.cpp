#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    int uniforms[31];

    // 초기화
    for (int i = 1; i <= n; i++)
    {
        uniforms[i] = 1;

        // 잃어버림
        for (int j = 0; j < lost.size(); j++)
        {
            if (i == lost[j])
            {
                uniforms[i]--;
            }
        }

        // 여벌
        for (int k = 0; k < reserve.size(); k++)
        {
            if (i == reserve[k])
            {
                uniforms[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // 잃어버린 학생 찾기
        if (uniforms[i] == 0)
        {
            // 여벌 건네주기
            if (i > 1 && uniforms[i - 1] == 2)
            {
                uniforms[i]++;
                uniforms[i - 1]--;
            }
            else if (uniforms[i + 1] == 2 && i < n)
            {
                uniforms[i]++;
                uniforms[i + 1]--;
            }
        }

        // 체육복을 가진 사람 세기
        if (uniforms[i] > 0)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    // 입력
    vector<int> lost;
    int n = 5; // 학생 수
    for (int i = 0; i < 2; i++)
    {
        int num;
        cin >> num;
        lost.push_back(num);
    }

    // 입력 2
    vector<int> reserve;
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        reserve.push_back(num);
    }

    cout << solution(n, lost, reserve);

    return 0;
}