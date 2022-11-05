#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int origin = n;

    // n�� ������ȯ ���� �� 1�� ��
    int oneCnt = 1;
    while (origin > 0)
    {
        int temp = origin % 2;
        if (temp == 1) { oneCnt++; }   // �������� 1�̸� ī����
        origin /= 2;
    }

    int loop = 0;   // �ݺ� ��
    while (true)
    {
        // 1�� �����ϸ� ����ȭ �������� 1�� �� ã��
        loop++;
        origin = n;
        origin += loop;
        int target = origin;
        int tempOneCnt = 1;

        while (origin > 0)
        {
            int temp = origin % 2;
            if (temp == 1) { tempOneCnt++; }
            origin /= 2;
        }

        // 1�� ���� ���� ���� ã���� �ߴ�
        if (tempOneCnt == oneCnt) { answer = target; break; }
    }

    return answer;
}

int main()
{
    int n = 15;
    int answer = solution(n);
    cout << answer;

    return 0;
}
