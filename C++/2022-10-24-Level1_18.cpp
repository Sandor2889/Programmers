#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;

    // ���� ��ü ���� a ���� ���� ������ �ݺ�
    while (n >= a)
    {
        int cola = b * (n / a);   // ��ȯ �� 
        n %= a;                   // ���� �� ��
        n += cola;                // ��ȯ �� �ݶ� ��������
        answer += cola;
    }

    return answer;
}

int main()
{
    int a = 3;
    int b = 2;
    int n = 10;

    int answer = solution(a, b, n);
    cout << answer;

    return 0;
}

