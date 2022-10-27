#include <iostream>

using namespace std;

// ���� a�� ����ǥ ��ġ��, b�� ��ġ�� ���� ���� round�� ã�� ���� �ٽ��̴�.
// (x / 2) + (x % 2) => x�� 2�γ��� ��� �������� ���ϸ� ���� ����ǥ�� ��ġ�� �� �� �ִ�. 
int solution(int n, int a, int b)
{
    int answer = 0;

    // a�� b�� ����ǥ ��ġ�� ���� �� ã��
    while (a != b)
    {
        ++answer;
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
    }

    return answer;
}

int main()
{
    int n = 8;
    int answer = solution(n, 4, 7);

    cout << answer;
}