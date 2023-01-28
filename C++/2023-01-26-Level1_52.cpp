#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ð��ʰ�
int solution_TimeOver(int number, int limit, int power) 
{
    int answer = 0;

    // number���� ������� Ž��
    for (int i = 1; i <= number; ++i)
    {
        int count = 0; // i�� ���� ����� ��
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0) { ++count; }
        }

        // count�� limit ���� ũ�� power�� ����
        if (count > limit) { count = power; }
        answer += count;
    }

    return answer;
}

// ����
int solution(int number, int limit, int power)
{
    int answer = 1; // 1�� ����� �׻� �� ��

    // 2���� number���� ������� Ž��
    for (int i = 2; i <= number; ++i)
    {
        int count = 0; // i�� ���� ����� ��

        // �ڽ� i�� �����ٱ��� ���ϸ� ��
        // 6 = 1 * 6, 2 * 3 -> 1, 2, 3, 6
        for (int j = 1; j * j <= i; ++j)
        {
            if (j * j == i) { ++count; } // ������ �ߺ� ����ó��
            else if (i % j == 0) { count += 2; }
        }

        // count�� limit ���� ũ�� power�� ����
        if (count > limit) { count = power; }
        answer += count;
    }

    return answer;
}

int main()
{
    int number = 5;
    int limit = 3;
    int power = 2;

    int answer = solution(number, limit, power);
    cout << answer;

    return 0;
}