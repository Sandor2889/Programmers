#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    int uniforms[31];

    // �ʱ�ȭ
    for (int i = 1; i <= n; i++)
    {
        uniforms[i] = 1;

        // �Ҿ����
        for (int j = 0; j < lost.size(); j++)
        {
            if (i == lost[j])
            {
                uniforms[i]--;
            }
        }

        // ����
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
        // �Ҿ���� �л� ã��
        if (uniforms[i] == 0)
        {
            // ���� �ǳ��ֱ�
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

        // ü������ ���� ��� ����
        if (uniforms[i] > 0)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    // �Է�
    vector<int> lost;
    int n = 5; // �л� ��
    for (int i = 0; i < 2; i++)
    {
        int num;
        cin >> num;
        lost.push_back(num);
    }

    // �Է� 2
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